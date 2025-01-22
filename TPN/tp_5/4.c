#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int count_newlines(int fd, off_t start, off_t end) {
    lseek(fd, start, SEEK_SET);
    char buffer[1024];
    ssize_t bytes_read;
    int newline_count = 0;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        for (ssize_t i = 0; i < bytes_read; i++) {
            if (start >= end) return newline_count;
            if (buffer[i] == '\n') newline_count++;
            start++;
        }
    }

    return newline_count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    // Obtenir la taille du fichier
    off_t file_size = lseek(fd, 0, SEEK_END);
    if (file_size == -1) {
        perror("Erreur lors de la lecture de la taille du fichier");
        close(fd);
        return 1;
    }

    // Diviser la taille en 4 parties
    off_t part_size = file_size / 4;
    pid_t pids[4];
    int pipe_fds[2];

    if (pipe(pipe_fds) == -1) {
        perror("Erreur lors de la création du pipe");
        close(fd);
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        pids[i] = fork();
        if (pids[i] < 0) {
            perror("Erreur lors de la création du processus");
            close(fd);
            return 1;
        } else if (pids[i] == 0) {
            // Code du fils
            close(pipe_fds[0]); // Fermer la lecture du pipe dans le fils
            off_t start = i * part_size;
            off_t end = (i == 3) ? file_size : (i + 1) * part_size;
            int count = count_newlines(fd, start, end);
            write(pipe_fds[1], &count, sizeof(count));
            close(pipe_fds[1]);
            close(fd);
            exit(0);
        }
    }

    // Code du père
    close(pipe_fds[1]); // Fermer l'écriture dans le pipe
    int total_newlines = 0;

    for (int i = 0; i < 4; i++) {
        int count;
        read(pipe_fds[0], &count, sizeof(count));
        total_newlines += count;
    }

    close(pipe_fds[0]);
    close(fd);

    for (int i = 0; i < 4; i++) {
        wait(NULL);
    }

    printf("Nombre total de lignes : %d\n", total_newlines);

    return 0;
}

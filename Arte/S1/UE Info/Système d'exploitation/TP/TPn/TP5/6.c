#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>

struct thread_args {
    int fd;
    off_t start;
    off_t end;
    int *result;
};

void* count_newlines_thread(void* arg) {
    struct thread_args *args = (struct thread_args*)arg;
    lseek(args->fd, args->start, SEEK_SET);

    char buffer[1024];
    ssize_t bytes_read;
    int newline_count = 0;
    off_t processed = args->start;

    while (processed < args->end && (bytes_read = read(args->fd, buffer, sizeof(buffer))) > 0) {
        for (ssize_t i = 0; i < bytes_read; i++) {
            if (processed >= args->end) break;
            if (buffer[i] == '\n') newline_count++;
            processed++;
        }
    }

    *(args->result) = newline_count;
    return NULL;
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

    // Diviser le fichier en 4 parties
    off_t part_size = file_size / 4;
    pthread_t threads[4];
    struct thread_args args[4];
    int results[4] = {0};

    for (int i = 0; i < 4; i++) {
        args[i].fd = fd;
        args[i].start = i * part_size;
        args[i].end = (i == 3) ? file_size : (i + 1) * part_size;
        args[i].result = &results[i];

        if (pthread_create(&threads[i], NULL, count_newlines_thread, &args[i]) != 0) {
            perror("Erreur lors de la création du thread");
            close(fd);
            return 1;
        }
    }

    int total_newlines = 0;

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
        total_newlines += results[i];
    }

    close(fd);

    printf("Nombre total de lignes : %d\n", total_newlines);
    return 0;
}
/*
gcc -o wc_threads exercice6_wc_threads.c -pthread
./wc_threads fichier.txt

*/
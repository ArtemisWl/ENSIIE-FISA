#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void sleepsort(int n, int *numbers) {
    for (int i = 0; i < n; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("Erreur lors de la création du processus fils");
            exit(1);
        } else if (pid == 0) {
            // Code du fils
            sleep(numbers[i]);
            printf("%d\n", numbers[i]);
            fflush(stdout);
            exit(0);
        }
    }

    // Attente des fils
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s n1 n2 ... nk\n", argv[0]);
        return 1;
    }

    int n = argc - 1;
    int numbers[n];

    for (int i = 0; i < n; i++) {
        numbers[i] = atoi(argv[i + 1]);
        if (numbers[i] < 0) {
            fprintf(stderr, "Tous les nombres doivent être positifs\n");
            return 1;
        }
    }

    sleepsort(n, numbers);

    return 0;
}
// gcc -o sleepsort exercice2_sleepsort.c 
// ./sleepsort 3 1 5 4 3
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

void run_with_fork(int n) {
    for (int i = 0; i < 1000; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("Erreur lors de la création du processus");
            exit(1);
        } else if (pid == 0) {
            // Processus fils
            printf("hello\n");
            exit(0);
        } else {
            // Processus père
            wait(NULL);
        }
    }
}

void* thread_routine(void* arg) {
    printf("hello\n");
    return NULL;
}

void run_with_threads(int n) {
    pthread_t threads[1000];

    for (int i = 0; i < 1000; i++) {
        if (pthread_create(&threads[i], NULL, thread_routine, NULL) != 0) {
            perror("Erreur lors de la création du thread");
            exit(1);
        }
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s fork|thread <memory_in_MB>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[2]);
    if (n <= 0) {
        fprintf(stderr, "La mémoire allouée doit être positive\n");
        return 1;
    }

    void* allocated_memory = malloc(n * 1024 * 1024);
    if (!allocated_memory) {
        perror("Erreur d'allocation mémoire");
        return 1;
    }

    memset(allocated_memory, 0, n * 1024 * 1024);

    clock_t start = clock();

    if (strcmp(argv[1], "fork") == 0) {
        run_with_fork(n);
    } else if (strcmp(argv[1], "thread") == 0) {
        run_with_threads(n);
    } else {
        fprintf(stderr, "Option non reconnue: %s\n", argv[1]);
        free(allocated_memory);
        return 1;
    }

    clock_t end = clock();
    printf("Temps d'exécution: %.2f secondes\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(allocated_memory);
    return 0;
}
/*gcc -o runcmd exercice5_runcmd.c -pthread
./runcmd fork 1
./runcmd thread 1
*/
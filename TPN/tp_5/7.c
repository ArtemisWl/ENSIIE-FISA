#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem1, sem2;

void* thread1_func(void* arg) {
    sem_wait(&sem1);
    printf("h");
    fflush(stdout);
    printf("o");
    fflush(stdout);
    sem_post(&sem2);
    return NULL;
}

void* thread2_func(void* arg) {
    sem_wait(&sem2);
    printf("ell");
    fflush(stdout);
    sem_post(&sem1);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Initialiser les sémaphores
    sem_init(&sem1, 0, 1); // thread1 démarre en premier
    sem_init(&sem2, 0, 0);

    // Créer les threads
    if (pthread_create(&thread1, NULL, thread1_func, NULL) != 0) {
        perror("Erreur lors de la création du thread 1");
        return 1;
    }

    if (pthread_create(&thread2, NULL, thread2_func, NULL) != 0) {
        perror("Erreur lors de la création du thread 2");
        return 1;
    }

    // Attendre la fin des threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Le thread principal écrit le '\n'
    printf("\n");

    // Détruire les sémaphores
    sem_destroy(&sem1);
    sem_destroy(&sem2);

    return 0;
}

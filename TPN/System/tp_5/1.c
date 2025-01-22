#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    // Créer le premier fils
    pid1 = fork();

    if (pid1 < 0) {
        perror("Erreur lors de la création du premier fils");
        exit(1);
    } else if (pid1 == 0) {
        // Code du premier fils
        sleep(2);
        printf("\n");
        fflush(stdout);
        exit(0);
    }

    // Créer le deuxième fils
    pid2 = fork();

    if (pid2 < 0) {
        perror("Erreur lors de la création du deuxième fils");
        exit(1);
    } else if (pid2 == 0) {
        // Code du deuxième fils
        sleep(1);
        printf(" world");
        fflush(stdout);
        exit(0);
    }

    // Code du père
    printf("hello");
    fflush(stdout);

    // Attendre la fin des fils
    wait(NULL);
    wait(NULL);

    return 0;
}


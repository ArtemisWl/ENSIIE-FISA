#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t fils1, petit_fils;

    // Créer le premier fils
    fils1 = fork();

    if (fils1 < 0)
    {
        perror("Erreur lors de la création du premier fils");
        exit(1);
    }
    else if (fils1 == 0)
    {
        // Code du premier fils
        petit_fils = fork();
        if (petit_fils < 0)
        {
            perror("Erreur lors de la création du petit fils");
            exit(1);
        }
        else if (petit_fils == 0)
        {
            sleep(1);
            printf("Comment ");
            fflush(stdout);
            exit(0);
        }
        sleep(3);
        wait(NULL);

        printf(" ca ");
        fflush(stdout);
        exit(0);
    }

    // Code du père
    sleep(4);
    printf(" va ?");
    fflush(stdout);
    wait(NULL);
    return 0;
}

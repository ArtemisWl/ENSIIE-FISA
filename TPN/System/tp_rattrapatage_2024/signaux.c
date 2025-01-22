#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h> 
#include <stdio.h>
#include <signal.h>

pid_t pid;

void onalarm(){




}


/*** fonction gestionnaire (qu'on nommera "onalarm") À COMPLÉTER ***/
    
int main()
{  
    int status;
    pid = fork();
    if (pid == -1)
        printf ("Erreur de création de processus\n");
    else
        {
            if (pid == 0)
                {
                    printf("Valeur du fork dans le fils: %d\n", pid);
                    printf("Je suis le fils, mon pid:%d\n",getpid());
                    fflush(stdout);
                    while(1);
                }
            else 
                {
                    printf("Valeur du fork dans le père: %d\n", pid);
                    printf("Je suis le père, mon pid:%d\n",getpid());
                    fflush(stdout);

                    /* **** À COMPLÉTER ***** */

                    alarm(5);
                    
                    wait(&status); 
                }
        }
    }
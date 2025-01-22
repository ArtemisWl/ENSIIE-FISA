Fiche récapitulative : Gestion des processus en C

La gestion des processus est un élément clé du système d'exploitation, permettant de créer, exécuter, et gérer plusieurs processus simultanément. Voici une récapitulation des concepts clés avec des exemples d'algorithmes en C.

1. Création d'un processus : fork()
La fonction fork() crée un nouveau processus (un enfant) à partir du processus actuel (le parent).

Retour de fork() :
Retourne 0 dans le processus enfant.
Retourne PID de l'enfant dans le processus parent.
Retourne -1 en cas d'échec.

Exemple d'algorithme :

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        // Erreur
        perror("Fork échoué");
        exit(1);
    } else if (pid == 0) {
        // Code du processus enfant
        printf("Enfant : Je suis un processus enfant\n");
    } else {
        // Code du processus parent
        printf("Parent : L'ID de l'enfant est %d\n", pid);
    }

    return 0;
}


2. Attente de la fin d'un processus : wait()
Le processus parent peut attendre que le processus enfant se termine en utilisant wait(), récupérant ainsi le code de sortie de l'enfant.

wait() : Attend la terminaison d'un enfant et peut récupérer son statut.
WEXITSTATUS(status) : Récupère le code de sortie du processus enfant.


Exemple d'algorithme :

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Code de l'enfant
        printf("Enfant : Je termine maintenant\n");
        _exit(0); // Termination propre de l'enfant
    } else {
        // Code du parent
        int status;
        wait(&status); // Attente de la fin de l'enfant
        printf("Parent : L'enfant a terminé avec le code %d\n", WEXITSTATUS(status));
    }

    return 0;
}
3. Exécution d'un autre programme : exec()
Les fonctions exec() permettent de remplacer l'image mémoire d'un processus par un autre programme (exécution d'un programme différent dans le même processus).

Exemple d'algorithme avec execlp() :

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Enfant : remplace son code par celui de `ls`
        execlp("/bin/ls", "ls", "-l", (char *)NULL);
        // Si execlp échoue, un message d'erreur
        perror("Erreur dans execlp");
    } else {
        // Parent : attend que l'enfant termine
        wait(NULL);
        printf("Parent : L'enfant a terminé\n");
    }

    return 0;
}
4. Envoi de signaux : kill() et gestion avec signal()
Les signaux sont des messages envoyés entre processus. Ils permettent de notifier un processus qu'un événement particulier a eu lieu.

kill(pid, signal) : Envoie un signal à un processus spécifié par son PID.
signal(signal, handler) : Définit un gestionnaire pour un signal.

Exemple d'algorithme avec kill() et SIGKILL :

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Enfant : attend un signal
        printf("Enfant : J'attends un signal\n");
        while (1) {
            sleep(1); // Attente active du signal
        }
    } else {
        // Parent : envoie un signal SIGKILL pour tuer l'enfant
        sleep(2); // Laisser le temps à l'enfant d'attendre
        kill(pid, SIGKILL); // Envoie SIGKILL
        printf("Parent : Signal SIGKILL envoyé à l'enfant\n");
    }

    return 0;
}
5. Fin de processus : exit() et _exit()
exit(code) : Termine un processus en libérant les ressources et en retournant un code de sortie.
_exit(code) : Termine un processus sans effectuer de nettoyage (utilisé après un fork() dans l'enfant).

Exemple d'algorithme avec exit() :

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Avant exit\n");
    exit(0);  // Terminer le processus avec un code de sortie 0
    printf("Ce code ne sera jamais exécuté\n");
}

6. Résumé des fonctions clés

Fonction	Description
fork()	Crée un nouveau processus (enfant).
wait()	Attend la fin d'un processus enfant.
exec()	Remplace l'image mémoire du processus avec un autre programme.
kill()	Envoie un signal à un processus.
signal()	Définit un gestionnaire pour un signal.
exit()	Termine un processus avec nettoyage des ressources.
_exit()	Termine un processus sans nettoyage (généralement après fork() dans l'enfant).


7. Schéma général de création de processus

Le processus parent appelle fork().
Le processus parent reçoit le PID de l'enfant et continue son exécution.
Le processus enfant reçoit 0 et exécute son propre code.
Le processus parent utilise wait() pour attendre la fin de l'enfant.
Les processus peuvent échanger des signaux via kill() ou être terminés via exit().
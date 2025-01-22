#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <assert.h>

void sigpipe(int sig) {
    assert(sig == SIGPIPE);
    fprintf(stderr, "SIGPIPE received... aborting in 5 seconds\n");
    sleep(5);
    exit(0);
}

int main(int argc, char* argv[]) {
    if (argc != 1) {
        fprintf(stderr, "usaage: %s\n", argv[0]);
        exit(1);
    }

    fprintf(stderr, "%s: started\n", argv[0]);
    signal(SIGPIPE, sigpipe);
    
    while (1) {
        char c;
        int statut = read(0, &c, 1);
        if (statut == -1) {
            perror("[read]");
            exit(2);
        } else if (statut == 0) {
            write(2, ".", 1);
            usleep(100000); /* 0.1s */
        } else { /* statut == 1 */
            write(1, &c, 1);
        }
    }

    return 0;
}
/*
— Une lecture sur f est bloquante, si f est vide et qu’il existe encore un écrivain. 
— Une écriture sur f est bloquante, si f est pleine et qu’il existe encore un lecteur.
— En absence de lecteur, une écriture sur une f génère l’émission du signal SIGPIPE. Si ce signal n’est ni attrapé, ni ignoré, ceci entraine l'arrêt du processus. Si ce signal est attrapé ou ignoré, l’écriture renvoie une erreur et la variable errno reçoit la valeur EPIPE. 
— Si P1 et P2 écrivent dans f, les données seront écrites soit l’une derrière l’autre, soit enchevêtrées. 
— Si P1 et P2 lisent dans f, ils ne peuvent pas lire la même donnée. 
— Si P1 fait une lecture et P2 une écriture dans f, P1 reçoit la donnée écrite par P2 si : 
    i. la FIFO f est vide, 
    ii. il n’y a pas d’autre écriture entre la lecture de P1 et l’écriture de P2, 
    iii. il n’y a pas d’autre lecture entre la lecture de P1 et l’écriture de P2. 
Si ces conditions sont réalisées, l’ordre chronologique de la lecture de P1 et l’écriture de P2 est respecté.
*/
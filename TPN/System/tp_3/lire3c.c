#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "/pub/FISE_OSSE11/syscall/lire.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Mauvais nombre d'arguments\n");
        return 1;
    }
    fprintf(stderr, "Je suis le programme lire.\n");
    int f1 = open(argv[1], O_RDONLY);
    if (f1 == -1) {
        perror("Erreur d'ouverture du fichier source");
        return 0;
    }
    int f2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(f2 == -1) {
        perror("Erreur d'ouverture du fichier destination");
        close(f1);
        return 0;
    }    
    
    lire();
    int clavier = dup(0);
    int ecran = dup(1);
    dup2(f1, 0); 
    dup2(f2, 1); 
    lire();
    dup2(clavier,0);
    dup2(ecran,1);
    execl("./lire", "lire", NULL);
    return 0;
}
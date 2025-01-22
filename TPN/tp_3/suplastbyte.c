#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[]){
    if (argc != 2) {
        fprintf(stderr, "Mauvais nombre d'arguments\n");
        return 1;
    }
    int fsrc = open(argv[1], O_RDONLY);
    if (fsrc == -1) {
        fprintf(stderr, "Erreur ouverture lecture: %s\n", strerror(errno));
        return 1;
    }

    int t = lseek(fsrc, 0, SEEK_END);
    if (t == -1) {
        fprintf(stderr, "Erreur lors de lseek: %s\n", strerror(errno));
        close(fsrc);
        return 1;
    }
    lseek(fsrc, 0, SEEK_SET);

    char *tabo = malloc((t - 1) * sizeof(char));
    if (tabo == NULL) {
        fprintf(stderr, "Erreur allocation mémoire\n");
        close(fsrc);
        return 1;
    }

    int status = read(fsrc, tabo, t - 1);
    if (status == -1) {
        fprintf(stderr, "Erreur lecture: %s\n", strerror(errno));
        free(tabo);
        close(fsrc);
        return 1;
    }

    close(fsrc);

    int fdes = open(argv[1], O_WRONLY | O_TRUNC);
    if (fdes == -1) {
        fprintf(stderr, "Erreur ouverture écriture: %s\n", strerror(errno));
        free(tabo);
        return 1;
    }

    status = write(fdes, tabo, t - 1);
    if (status == -1) {
        fprintf(stderr, "Erreur écriture: %s\n", strerror(errno));
        free(tabo);
        close(fdes);
        return 1;
    }

    close(fdes);
    free(tabo);

    return 0;
}
/*
lit un fichier, supprime son dernier octet,
puis réécrit le contenu modifié dans le même fichier.
*/
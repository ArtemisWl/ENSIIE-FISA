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
    FILE *fsrc =fopen(argv[1], "r");
    if (fsrc == NULL) {
        fprintf(stderr, "Erreur ouverture lecture: %s\n", strerror(errno));
        return 1;
    }
    fseek(fsrc, 0, SEEK_END);
    int t= ftell(fsrc);
    if (t == -1) {
        fprintf(stderr, "Erreur lors de lseek: %s\n", strerror(errno));
        fclose(fsrc);
        return 1;
    }
    fseek(fsrc, 0, SEEK_SET);

    char *tabo = malloc(t * sizeof(char));
    if (tabo == NULL) {
        fprintf(stderr, "Erreur allocation mémoire\n");
        fclose(fsrc);
        return 1;
    }

    int status = fread(tabo, sizeof(char),t-1,fsrc);
    if (status == -1) {
        fprintf(stderr, "Erreur lecture: %s\n", strerror(errno));
        free(tabo);
        fclose(fsrc);
        return 1;
    }

    fclose(fsrc);
    FILE *fdes;
    fdes = fopen(argv[1], "w+");
    if (fdes == NULL) {
        fprintf(stderr, "Erreur ouverture écriture: %s\n", strerror(errno));
        free(tabo);
        return 1;
    }
    fseek(fdes, 0, SEEK_END);

    status = fwrite(tabo, sizeof(char),t-1,fdes);
    if (status == -1) {
        fprintf(stderr, "Erreur écriture: %s\n", strerror(errno));
        free(tabo);
        fclose(fdes);
        return 1;
    }

    fclose(fdes);
    free(tabo);

    return 0;
}
/*
lit un fichier, supprime son dernier octet,
puis réécrit le contenu modifié dans le même fichier.
(en utilisant FILE)
*/
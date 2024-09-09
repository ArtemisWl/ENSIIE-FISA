#include "stdio.h"


int somme(n) {
    int res = (n*(n+1))/2;
    printf("La somme de tout les entiers de 0 à %d est : %d\n", n, res);
    return (res);
}

int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    if (n < 10) {
        printf("Le nombre choisi est inférieur à 10 donc le calcul sera éfféctué avec n = 10\n");
        int res = somme(10);
    }
    else {
        int res = somme(n);
    }
    return 0;
}
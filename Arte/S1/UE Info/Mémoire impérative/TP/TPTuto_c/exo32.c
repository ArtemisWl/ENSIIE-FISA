#include <stdio.h>
#include "stdlib.h"

int main(int argc, char* argv[]) {
    if(argc != 3) {
        fprintf(stderr, "2 arguments sont requis\n");
    }
    else {
        int x, z, som, prod, dif;
        x = atoi(argv[1]);
        z = atoi(argv[2]);
        som = x+z;
        prod = x*z;
        dif = x-z;
        if(z != 0) {
            double div = (double)x/(double)z;
            printf("La somme de %d et %d est : %d, leur produit est : %d, leur différence est : %d et leur division est : %lf\n", x, z, som, prod, dif, div);
        }
        else {
            printf("La somme de %d et %d est : %d, leur produit est : %d, leur différence est : %d et la division est impossible\n", x, z, som, prod, dif);
        }
        
    }
    return 0;
}
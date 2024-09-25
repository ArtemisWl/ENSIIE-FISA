#include "stdio.h"


int evergure(int tab[], int size) {
    int res = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(tab[i] == tab[j] && i != j) {
                if (res < (j - i)) {
                    res = j - i;
                }
            }
        }
    }
    return res;
}


int main() {
    int tab[8] = {4, 1, 9, 5, 9, 2, 5, 5};

    printf("La plus grande distance entre deux éléments identiques est de %d\n", evergure(tab, 8));
    return 0;
}
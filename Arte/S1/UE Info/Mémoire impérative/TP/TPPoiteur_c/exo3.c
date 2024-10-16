#include <stdio.h>
#include <stdlib.h>

void minMax(int size, int tab[], int * min, int * max) {
    *min = tab[0];
    *max = tab[0];
    for (int i = 0; i < size; i++) {
        if (tab[i] < *min) {
            *min = tab[i];
        }
        if (*max < tab[i]) {
            *max = tab[i];
        }
    }
}

int main() {
    int tab[10] = {3, 3, 2, 3, 4, 18, 6, 7, 8, 9};
    int  min, max;
    minMax(10, tab, &min, &max);
    printf("Min : %d, Max : %d \n", min, max);
    return 0;
}
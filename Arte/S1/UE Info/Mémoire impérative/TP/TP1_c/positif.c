#include "stdio.h"

int main(void) {
    int x = -2;
    printf("L'entier x : %d est " , x);
    if (x >= 0) {
        printf("POSITIVE\n");
    }
    else {
        printf("NEGATIF\n");
    }
    return 0;
}
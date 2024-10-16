#include <stdio.h>
#include <stdlib.h>

int * initP() {
    int * res = (int *) malloc(1 * sizeof(int));
    *res = 0;
    return res;
}

void finP(int * p) {
    free(p);
}

int main() {
    int * test;
    test = initP();
    printf("Test : %d ", *test);
    printf("Test : %d \n", &test);

    finP(test);

    printf("Test : %d ", *test);
    printf("Test : %d \n", &test);

    return 0;
}
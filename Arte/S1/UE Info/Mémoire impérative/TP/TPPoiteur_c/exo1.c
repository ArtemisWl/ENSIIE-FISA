#include <stdio.h>

void echange(int * a, int * b, int * c) {
    int tmp = *a;
    *a = *c;
    *c = *b;
    *b = tmp;
}

int main() {

    int a = 1, b = 2, c = 3;

    echange(&a, &b, &c);

    printf("a = %d, b = %d, c = %d \n", a, b, c);

    return 0;
}
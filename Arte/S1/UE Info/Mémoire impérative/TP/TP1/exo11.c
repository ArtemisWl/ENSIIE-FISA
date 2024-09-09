#include "stdio.h"

int main(void) {
    double x, y;
    //x = 340282346638528859811704183484516925440.0-1;
    //y = 340282346638528859811704183484516925440.0-10;
    x = 1/34028234.0;
    y = ((1/34028234.0)+3)-3;
    if (x == y) {
        printf("X et Y sont égaux\n");
    }
    else {
        printf("X et Y ne sont pas égaux\n");
    }
    return 0;
}
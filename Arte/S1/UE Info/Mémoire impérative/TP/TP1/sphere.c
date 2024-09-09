#include "stdio.h"

int main(void) {
    int r = 5;
    double pi = 3.14;
    double v = (4.0/3.0)*pi*(double)r*(double)r*(double)r;
    printf ("Volume d'une sphère de rayon %d = %lf\n", r, v);
    return 0;
}
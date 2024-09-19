#include <stdio.h>

int main(void) {
    int x1 = 2;
    int y1 = 4;
    int x2 = 7;
    int y2 = 9;
    double xm = ((double)x1 + (double)x2)/2;
    double ym = ((double)y1 + (double)y2)/2;

    printf("Point P1 : (%d, %d)\n", x1, y1);
    printf("Point P2 : (%d, %d)\n", x2, y2);
    printf("Milieu de P1 et P2 : (%lf, %lf)\n", xm, ym);
    return 0;
}
    
#include "stdio.h"
#include "math.h"


double gravite(int m1, int m2, int d) {
    double G = 6.67*pow(10, -1);
    double res = (G*m1*m2)/d*d;
    return (res);
}

int main() {
    double res = gravite(2,4,10);
    printf("Le résultat esr : %lf\n", res);
    return 0;
}
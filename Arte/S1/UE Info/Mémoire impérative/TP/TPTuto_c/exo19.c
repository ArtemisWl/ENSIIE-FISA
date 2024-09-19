#include "stdio.h"

double perim(double r) {
    double res = 2*3.14*r;
    return res;
}

double air(double r) {
    double res = 3.14*r*r; 
    return res;
}

void airV(double r, double h) {
    double volume = air(r)*h; 
    double airC = 2*air(r) + perim(r)*h;
    printf("L'air et le volume d'un cylindre de rayon %lf et de hauteur %lf sont de : %lf et %lf\n", r, h, airC, volume);
}

int main() {
    airV(4, 2);
    return 0;
}
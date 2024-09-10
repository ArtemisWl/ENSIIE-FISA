#include "stdio.h"

int main(void) {
    int a = 2;
    int b = 3;
    double c2 = (double)a*(double)a + (double)b*(double)b; 
    
    printf("Carré de l'hyponénuse d'un triangle réctangle de coté %d et %d = %lf\n", a , b ,c2);
    return 0;
}
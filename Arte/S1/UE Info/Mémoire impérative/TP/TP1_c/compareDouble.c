#include "stdio.h"

int main(void) {
    double x, y, res;
    x = 3.14;
    y = 2.71;
    res = x - y;
    if ((res >= 0 && res < 0.001) || (res < 0 && res > 0.001)) {
        printf("Les chiffres %lf et %lf sont égaux\n", x , y);       
    }
    else {
        printf("Les chiffres %lf et %lf ne sont pas égaux\n", x , y);
    }
    return 0;
}
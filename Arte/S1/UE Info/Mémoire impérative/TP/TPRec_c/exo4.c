#include <stdio.h>
#include <stdbool.h>


double logIt(double x) {
    if(1 <= x || x <= 0) {
        return -1.0;
    }

    double l = 0.0;
    int i = 1;
    double xi = 1;
    while(true) {
        xi *= x;
        if (xi/i < 0.001) {
            return l;
        }
        else {
            l += xi/i;
        }
        i++;
    }
}

double logRec(double x, int ind, double xi, double acc) {
    if (x <= 0 || x >= 1) 
        return -1.0;
    
    if (xi / ind < 0.001) {
        return acc;
    } else {
        return logRec(x, ind + 1, xi * x, acc + xi/ind);
    }
}


int main() {

    double res = logRec(0.2, 1, 0.2, 0.0);

    printf("%f\n", res);

    return 0;
}
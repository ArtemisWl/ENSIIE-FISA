#include "stdio.h"
#include "math.h"

double nlogn(int n) {
    double res =n*log(n);
    printf("%lf\n", res);
    return (res);
}

int main() {
    nlogn(2);
    return 0;
}
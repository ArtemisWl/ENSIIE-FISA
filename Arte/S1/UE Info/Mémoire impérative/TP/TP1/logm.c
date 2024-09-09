#include "stdio.h"
#include "math.h"

double logm(int n, int m){
    int tmp = n;
    printf("Le log de %d en base %d est : ", n , m);
    while(tmp > m) {
        tmp /= m;
        if((tmp == m) || (floor(tmp) == m)) {
            tmp = floor(tmp);
            printf("%d\n" , tmp);
            return (double)tmp;
        }
    }
    return 0.0;
}

int main(void) {
    logm(17, 4);
    return 0;
}
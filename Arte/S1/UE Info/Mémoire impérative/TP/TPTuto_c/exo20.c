#include "stdio.h"
#include "math.h"

void table(int x) {
    int tmp;
    printf("Table de %d : \n", x);
    for(int i=0; i<11; i++) {
        tmp = i*x;
        printf("%d * %d = %d\n" , x , i, tmp);
    }
}

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

int main(){
    table(4);
    logm(17,4);
    return 0;
}
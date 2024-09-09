#include "stdio.h"
#include "stdlib.h"

int main(int argc, char* argv[]) {
    int tmp, x;
    x = atoi(argv[1]);
    printf("Table de %d : \n", x);
    for(int i=0; i<11; i++) {
        tmp = i*x;
        printf("%d * %d = %d\n" , x , i, tmp);
    }
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int* point(int n){
    int* arr = (int*)malloc(2 * sizeof(int));
    arr[0] = n;
    arr[1] = n;
    return arr;
}

int main(){
    int n=5;
    int* p = point(n);
    printf("Les valeurs sont : %d et %d\n", p[0], p[1]);
    free(p);
    return 0;
}
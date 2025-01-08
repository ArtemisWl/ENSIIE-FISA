#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int f(double *x){
    if(*x<0){
        *x=-(sqrt((-*x)));
    }else{
        *x=sqrt((*x));
    }
}
int main(){
    double x=0;
    f(&x);
    printf("%f",x);
}
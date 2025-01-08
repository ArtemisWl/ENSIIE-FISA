#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int u(int n){
    if(n==0){
        return 0;


    }
    if(u(n-1)<0){
        return(-(u(n-1)+3));
    }
    return(u(n-1)-7);

}

int main(){
    int n=5;
    int res=u(n);
    printf("La valeur de u(%d) est : %d\n", n, res);




}
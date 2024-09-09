#include "stdio.h"


void triangle(int n) {
    int base = 2*n - 1;
    int tmp = n;
    while(tmp > 0) {
        if (tmp == n) {
            for(int i = 0; i < base; i++) {
                if(i == base-1) {
                    printf("*\n");
                }
                else {
                    printf("*");
                }
                
            }
        }
        else {
            for(int i = 0; i < base; i++) {
                if (i%2 == 0) {
                    printf("*");
                }
                else if(i == base -1) {
                    printf("*\n");
                }
                else {
                    printf(" ");
                }
            }
        }
        base -= 1;

    }
}

int main() {
    //AFINIR

    return 0;
}
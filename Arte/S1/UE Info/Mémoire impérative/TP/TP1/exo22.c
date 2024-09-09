#include "stdio.h"


void triangle(int n) {
    int base = 2*n - 1;
    for(int i = 0; i < n; i++) {
        if (i == 0) {
            for(int j = 0; j < base; j++) {
                printf("*");
                if (j == base - 1) {
                    printf("\n");
                }
            }    
        }
        else {
            for(int j = 0; j < base; j++) {
                if( j == 0) {
                    printf("*");
                }
                else {
                    if(j == base - 1) {
                        printf("*\n");
                    }
                    else {
                        printf(" ");
                    }
                }
            }
        }
        base -= 2;
    }
}

int main() {
    triangle(4);
    return 0;
}
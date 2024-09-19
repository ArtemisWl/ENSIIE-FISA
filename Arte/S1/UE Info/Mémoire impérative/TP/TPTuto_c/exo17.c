#include "stdio.h"

int main(int argc, char* argv[]) {
    int n;
    n = atoi(argv[1]);
    for(int i = 0; i < n; i++) {
        if ((i == 0) || (i == n-1)) {
            for(int j = 0; j < n; j++){
                printf("*  ");
                if (j==n-1){
                    printf("\n");
                }
            }
        }
        else {
            for(int j = 0; j < n; j++){
                if (j == 0) {
                    printf("*  ");
                }
                else if(j == n-1) {
                    printf("*\n");
                }
                else {
                    printf("   ");
                }
            }
        }
    }
    return 0;
}
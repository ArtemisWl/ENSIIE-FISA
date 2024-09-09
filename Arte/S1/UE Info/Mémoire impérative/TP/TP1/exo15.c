#include "stdio.h"

int main() {
    int i = 0;
    while ((i*i*i <= 1548) && ((i+1)*(i+1)*(i+1) <= 1548)) {
        i += 1;
        if ((i*i*i <= 1548) && ((i+1)*(i+1)*(i+1) > 1548)) {
            printf("L'int i tel que i³ <= 1548 < (i+1)³ est : %d\n" , i);
            return 0;
        }
    }
    printf("L'int i tel que i³ <= 1548 < (i+1)³ est : %d\n" , i);
    return 0;
}
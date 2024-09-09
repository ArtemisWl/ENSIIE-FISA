#include <stdio.h>

int abs(int n){
    if (n >= 0){
        return n;
    }
    else {
        return -n;
    }
}

void norme1(int n) {
    int t = 2 * n + 1;
    int m = n;  
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            if (abs(i - m) + abs(j - m) <= n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Entrez la valeur de n: ");
    scanf("%d", &n);
    norme1(n);

    return 0;
}

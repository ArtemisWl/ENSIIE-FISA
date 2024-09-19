#include "stdio.h"


void regroup(int t1[], int t2[], int n) {
    int count;
    for(int i = 0; i < n; i++) {
        if (n < t1[i] || t1[i] < 0) {
            printf("t1 ne contient des entiers négatifs ou supérieurs à sa taille");
            return;
        }
    }
    for(int i=0; i < n ; i++) {
        count = 0;
        for(int j = 0; j < n; j++) {
            if(t1[i] == t1[j]) {
                count++;
            }
        }
        t2[t1[i]] = count;
    }
}



int main() {
    int tab[10] = {0,1,1,1,4,5,6,7,8,9};
    int tab2[10];

    regroup(tab, tab2, 10);

    for(int i = 0; i < 10; i++) {
        printf("%d, ", tab2[i]);
    }
    printf("\n");
    return 0;
}
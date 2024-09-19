#include <stdio.h>

int appartient(int size, int tab[], int m) {
    for(int i = 0; i < size; i++) {
        if(tab[i] == m) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int tab[10];
    for(int i = 0; i < 10; i++) {
        tab[i] = i;
    }
    int res = appartient(10, tab, 17);
    printf("%d", res);
    return 0;
}
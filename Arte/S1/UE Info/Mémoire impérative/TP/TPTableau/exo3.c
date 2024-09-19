#include <stdio.h>

int appartient(int size, int tab[], int m) {
    for(int i = 0; i < size; i++) {
        if(tab[i] == m) {
            return 1;
        }
    }
    return 0;
}

int dich(int size, int tab[], int m) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = (right + left)/2;
        if(tab[mid] == m) {
            return 1;
        }
        else if(tab[mid] < m) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return 0;
}

void inverse(int size, int tab1[], int tab2[]) {
    for(int i = 0; i < size; i++) {
        tab2[i] = tab1[size - 1 -i];        
    }
}

int main() {
    int tab1[10];
    int tab2[10];
    for(int i = 0; i < 10; i++) {
        tab1[i] = i;
    }
    inverse(10, tab1, tab2);
    for(int i = 0; i < 10; i++) {
        printf("%d\n", tab2[i]);
    }
    return 0;
}
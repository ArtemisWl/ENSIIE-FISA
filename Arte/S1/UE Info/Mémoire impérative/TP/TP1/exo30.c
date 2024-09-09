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

int main() {
    int tab[10];
    for(int i = 0; i < 10; i++) {
        tab[i] = i;
    }
    int res = dich(10, tab, 15);
    printf("%d", res);
    return 0;
}
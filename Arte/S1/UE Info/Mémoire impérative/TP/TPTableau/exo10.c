#include "stdio.h"

int permut(int tab[], int size, int k) {
    int left = 0, right = size-1, count = 0, tabcal[size];

    for(int i = 0; i < size; i++) {
        tabcal[i] = tab[i];
    }

    while(left < right) {
        while(left < size && tabcal[left] < k) {
            left++;
        }
        while(right>=0 && tabcal[right] >= k) {
            right--;
        }
        if(left<right) {
            int tmp = tabcal[left];
            tabcal[left] = tabcal[right];
            tabcal[right] = tmp;
            count++;
        }
    }
    return count;
}


int main() {
    int tab[10] = {9,1,1,1,4,5,6,7,8,9};

    int perm = permut(tab, 10, 5);

    printf("%d permut\n", perm);

    return 0;
}
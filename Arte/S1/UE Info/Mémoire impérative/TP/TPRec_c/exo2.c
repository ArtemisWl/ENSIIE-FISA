#include <stdio.h>


int dichoRec(int min, int max, int tab[], int x) {
    if(max < min) {
        return -1;
    }

    int mid = (min + max)/2;
    if(tab[mid] == x) {
        return mid;
    }
    if(x > tab[mid]) {
        printf("test2\n");
        return dichoRec(mid+1, max, tab, x);
    }
    return dichoRec(min, mid-1, tab, x);

}

int main() {

    int tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10};

    int res = dichoRec(0, 10, tab, 3);

    printf("L'elem est à l'indice : %d\n", res);

    return 0;
}
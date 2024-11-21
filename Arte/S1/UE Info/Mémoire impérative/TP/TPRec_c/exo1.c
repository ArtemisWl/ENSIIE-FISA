#include <stdio.h>


int rec(int n) {
    if(0 <= n) {
        if(n <= 1) {
            return 1;
        }
        else {
            return n*rec(n-1);
        }
    }
    else {
        return -1;
    }
}

int recTerm(int n, int acc) {
    if(0 <= n) {
        if(n <= 1) {
            return acc;
        }
        else {
            return recTerm(n-1, acc*n);
        }
    }
    else {
        return -1;
    }
}



int main() {

    int x = rec(5);
    int y = recTerm(5,1);

    printf("%d,   %d\n", x, y);

    return 0;
}
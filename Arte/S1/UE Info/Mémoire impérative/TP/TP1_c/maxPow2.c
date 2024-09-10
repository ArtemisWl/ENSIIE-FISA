#include "stdio.h"

int pow2(int n) {
    int res=1;
    for (int i = 0; i<=n; i++) {
        res *= 2;
    }
    return res;
}

int main() {
    int i = 0;
    while (pow2(i)<=147483647) {
        if (147483647 < pow2(i+1)) {
            printf("La puissance de 2 maximale est : %d\n", i);
            return 0;
        }
        else {
            i += 1;
        }
    }
    return 0;
}  
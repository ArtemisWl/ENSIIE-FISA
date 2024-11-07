#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 10

int ** pointeursType(int size, int * l) {
    int ** res = (int **) malloc(2*sizeof(int *));
    int * even = (int *) malloc((size+1)*sizeof(int));
    int * odd = (int *) malloc((size+1)*sizeof(int));
    even[0] = 0, odd[0] = 0;
    res[0] = even, res[1] = odd;

    for (int i = 0; i < size; i++) {
        if (l[i]%2 == 0) {
            even[0]++;
            even[even[0]] = l[i];
        }
        else {
            odd[0]++;
            odd[odd[0]] = l[i];
        }
    }

    return res;
}


int main(void) {
    int * test = (int *) malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        test[i] = i;
    }

    int ** verif = pointeursType(n, test);

    for (int i = 0; i <= verif[0][0]; i++) {
        printf("Impaire : %d\n", verif[0][i]);
    }
    for (int i = 0; i <= verif[1][0]; i++) {
        printf("Paire : %d\n", verif[1][i]);
    }

    free(test);
    free(verif[0]);
    free(verif[1]);
    return 0;
}

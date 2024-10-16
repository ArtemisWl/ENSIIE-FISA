#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float * loglist(int n) {
    float * res = (float *) malloc(n*sizeof(float));
    for (int i = 1; i <= n; i++) {
        res[i] = log(i);
    }
    return res;
}

int main() {
    float * test = loglist(5);
    for (int i = 1; i <= 5; i++) {
        printf("%f\n", test[i]);
    }
    free(test);
    return 0;
}
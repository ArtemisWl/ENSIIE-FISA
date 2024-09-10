#include <stdio.h>
#include "stdlib.h"
#include "math.h"

int isNumber(char* str) {
    int i = 0;
    for (; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; 
        }
    }
    return 1;
}

int main(int argc, char* argv[]) {
    if(argc != 4) {
        fprintf(stderr, "3 arguments sont requis\n");
    }
    else if(isNumber(argv[1]) && isNumber(argv[2]) && isNumber(argv[3])){
        double a = atod(argv[1]), b = atod(argv[2]), c = atod(argv[1]);
        double hyp = max(max(a, b), c);
        if(hyp*hyp == a*a + b*b) {
            printf("Il existe un triangle rectangle avec ses longueure\n");
        }
        else {
            printf("Il n'existe pas un triangle rectangle avec ses longueure\n");
        }
    }
    return 0;
}
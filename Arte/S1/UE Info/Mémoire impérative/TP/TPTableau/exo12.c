#include <stdio.h>
#include <string.h>

void printFor(const char* c) {
    for(int i = 0; i < (int)strlen(c); i++) {
        printf("%c", c[i]);
    }
}


int main(int argc, char* argv[]) {
    if (2 < argc) {
        for (int i = 2; i < argc; i++) {
            if(i != 1 && i != argc-1) {
                printFor(argv[i]);
                printFor(argv[1]);
            }
            else {
                printFor(argv[i]);
            }
        }
        printf("\n");
    }
    else {
        printf("Ce programme prend minimum 2 argument en entré\n");
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

void printFor(const char* c) {
    for(int i = 0; i < (int)strlen(c); i++) {
        printf("%c", c[i]);
    }
}


int main(int argc, char* argv[]) {
    if (argc == 3) {
        for (int i = 0; i < (int)strlen(argv[2]); i++) {
            if (argv[2][i] == argv[1][0]) {
                printf("\n");
            }
            else {
                printf("%c", argv[2][i]);
            }
        }
        printf("\n");
    }
    else {
        printf("Ce programme prend 2 argument en entré\n");
    }
    return 0;
}
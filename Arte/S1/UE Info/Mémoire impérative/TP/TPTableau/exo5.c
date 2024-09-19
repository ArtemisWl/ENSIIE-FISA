#include <stdio.h>
#include <string.h>

void printFor(const char* c) {
    for(int i = 0; i < (int)strlen(c); i++) {
        printf("%c\n", c[i]);
    }
}

void printWhile(const char* c) {
    int i = 0;
    while(c[i] != '\0') {
        printf("%c\n", c[i]);
        i++;
    }
}

int main(){
    const char* c = "test"; 
    printFor(c);
    printWhile(c);
    return 0;
}
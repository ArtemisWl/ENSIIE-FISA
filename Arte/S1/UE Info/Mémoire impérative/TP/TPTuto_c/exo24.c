#include "stdio.h"
#include "string.h"

void concat(char* c, const char* s, const char* t) {
    int i = 0, j = 0;

    while (s[i] != '\0') {
        c[i] = s[i];
        i++;
    }
    
    while (t[j] != '\0') {
        c[i] = t[j];
        i++;
        j++;
    }
    c[i] = '\0';
}

void duplicat(char* c, const char* s, int n) {
    c[0] = '\0'; 
    char temp[1000];  

    for (int i = 0; i < n; i++) {
        concat(temp, c, s);  
        strcpy(c, temp);         
    }
}


int main() {
    char c[1000];
    const char* s = "testcomplet2";
    const char* t = "testcpmplet 3";
    concat(c, s, t);
    printf("%s\n", c);
    duplicat(c, s, 4);
    printf("%s\n", c);
    return 0;
}
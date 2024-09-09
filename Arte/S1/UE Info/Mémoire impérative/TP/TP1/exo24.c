#include "stdio.h"
#include "string.h"

char concat(char* c, char* s, char* t) {
    int ns = strlen(s);
    int nt = strlen(t);
    char c[ns + nt];
    for(int i = 0; i < ns + nt; i++){
        if( i < ns) {
            c[i] = s[i];
        }
        else {
            c[i] = t[i - ns];
        }
    }
    printf("%s", c);
    return c;
}


int main() {
    char* s = "test";
    char* t = "print";
    char* c = "c";
    concat(c, s, t);
    return 0;
}
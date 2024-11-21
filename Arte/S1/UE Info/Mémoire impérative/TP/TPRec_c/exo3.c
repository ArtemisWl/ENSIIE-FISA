#include <stdio.h>

void replace(char *str, char c, char d, int i) {
    if(str[i] == '\0') {
        return;
    }
    else {
        if(str[i] == c) {
            str[i] = d;
        }
        replace(str, c, d, i+1);
    }
}


int main() {
    
    char str[] = "abcabca";
    
    replace(str, 'a', 'z', 2);

    for(int i = 0; i<7; i++) {
        printf("%c", str[i]);
        printf("\n");
    }

    return 0;
}
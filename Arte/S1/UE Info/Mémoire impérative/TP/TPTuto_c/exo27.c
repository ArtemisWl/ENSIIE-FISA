#include <stdio.h>
#include <string.h>

int palindrome(const char* c) {
    int len = strlen(c);
    int clk = len / 2; 
    for (int i = 0; i < clk; i++) {
        if (c[i] != c[len - i - 1]) {
            return 0; 
        }
    }
    return 1; 
}

void devientPal(char* p, const char* s) {
    int i = 0;
    while (s[i] != '\0') {
        p[i] = s[i];
        i++;
    }
    int j = i -1;
    while (0 <= j) {
        p[i] = s[j];
        i++;
        j--;
    }
}

int main() {
    char* p[1000];
    const char* c = "test"; 
    int res = palindrome(c);
    printf("%d\n", res); 
    devientPal(p ,c);
    palindrome(p);
    printf("%s\n", p); 
    return 0;
}

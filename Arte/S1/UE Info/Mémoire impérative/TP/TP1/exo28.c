#include <stdio.h>
#include <ctype.h>

int isNumber(char *str) {
    int i = 0;
    for (; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; 
        }
    }
    return 1;
}

int main() {
    char str[100];

    printf("Entrez une chaîne de caractères : ");
    scanf("%s", str);

    if (isNumber(str)) {
        printf("La chaîne est un entier.\n");
    } else {
        printf("La chaîne n'est pas un entier.\n");
    }
    return 0;
}

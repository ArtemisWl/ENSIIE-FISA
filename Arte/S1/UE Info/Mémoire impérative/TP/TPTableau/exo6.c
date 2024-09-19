#include <stdio.h>

int main(){
    char s1 [10];
    s1[0] = 'a';
    s1[1] = 'b';
    s1[2] = 'c';
    s1[3] = 'd';
    printf ( "%s\n" ,s1);
    return 0;
}


//Les caractères qu'on arenseigner sont affiché mais la mémoire réservé n'est pas utilisé pour s1 mais contients des données on visualise donc des choses
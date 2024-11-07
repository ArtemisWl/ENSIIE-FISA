# TD Pointeur - Mémoire Impérative

## Exercice 7 - Retour au tuto

### Question 1 Le code n’est pas correct, pourquoi ?

```c
    #include <stdio.h>
    #include <stdlib.h>

    int * adress(int x) {

        int * px = (int*) malloc(sizeof(int));
        px = &x;
        return px;
    }

    int main () {

        int x = 2;
        int * px2 = adress(x) ;
        printf("%p", px2) ;
        free(px2);
    }
```

### Question 2 Le code n’est pas correct, pourquoi ?

```c
#include <stdio.h>
#include <stdlib.h>

char * hello(){
    char * px = "hello";
    return px;
}

int main (){

    char * s = hello();
    printf("%s", s);
    free(s);
}
```
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int repetition(int size, char* tab){
    for(int i=0; i<size-1; i++){
        if(tab[i] == tab[i+1]){
            return 1;
        }
            
        }return 0;
    }


int main(){
    char tab[]="abtac";
    int size=strlen(tab);
    if(repetition(size,tab)==1){
        printf("REP");
    }else printf("PAS REP");
}
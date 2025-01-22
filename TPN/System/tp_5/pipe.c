#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/wait.h>


int main()
{
   int pipefd[2];
   int count=0;
     if (pipe(pipefd) == -1)
     {
          perror("pipe");
          exit(1);
     }
   while(1){
    char a = 'a';
    
    printf("%d ",count);
    count++;
    fflush(stdout);
    write(pipefd[1],&a,sizeof(char));
    
   }
   return 0;
}
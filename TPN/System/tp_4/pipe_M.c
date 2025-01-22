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
 if (pipe(pipefd) == -1)
{
    perror("pipe");
    exit(1);
}
int nb = 0;
while (1)
{
    char c = 'a';
    nb++;
    printf("nb=%d\n", nb);

    if (write(pipefd[1], &c, sizeof(char)) == -1)
    {
        perror("write");
        exit(1);
    }
    
}
close(pipefd[1]);

}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <assert.h>

int main(int argc, char *argv[])
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
        write(pipefd[1], &c, sizeof(char));
               
    }
}

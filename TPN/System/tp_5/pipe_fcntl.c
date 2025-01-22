#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pipefd[2];
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(1);
    }

    // Set the write end of the pipe to non-blocking
    if (fcntl(pipefd[1], F_SETFL, O_NONBLOCK) == -1)
    {
        perror("fcntl");
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

    return 0;
}
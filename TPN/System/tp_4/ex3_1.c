#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }
    fcntl(fd[1],F_SETFL,O_NONBLOCK);
    int count = 0;
    char c = 'a';

    while (1) {
        if (write(fd[1], &c, 1) == -1) {
            perror("write");
            exit(1);
        }
        printf("nb = %d  \n", ++count);
    }

    close(fd[0]);
    close(fd[1]);
    return 0;
}

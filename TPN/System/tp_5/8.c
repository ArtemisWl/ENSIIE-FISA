#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
void fils(int com[], int fin)
{
    int ret;
    char c;
    printf("START");
    while ((ret = read(fin, &c, 1)) == 1)
    {
        printf("A");
        if (write(com[1], &c, 1) == -1)
        {
            
            perror("[fils.write]");
            exit(1);
        }
    }
    printf("B");
    if (ret == -1)
    {
        perror("[fils.read]");
        exit(2);
    }
    printf("C");
    exit(0);
}
int main()
{
    int ret;
    char c;
    int com[2];
    if (pipe(com) == -1)
    {
        perror("[pipe]");
        exit(1);
    }
    int in = open("in", O_RDONLY);
    int out = open("out", O_WRONLY | O_TRUNC);
    if (in == -1 || out == -1)
    {
        printf("ERR");
        perror("[open]");
        exit(2);
    }
    if ((ret = fork()) == -1)
    {
        printf("ERR");
        perror("[fork]");
        exit(3);
    }
    if (ret == 0)
        fils(com, in);
    if ((ret = fork()) == -1)
    {
        printf("ERR");
        perror("[fork]");
        exit(4);
    }
    if (ret == 0)
        fils(com, in);
    close(com[1]);
    printf("D");
      
    while ((ret = read(com[0], &c, 1)) == 1)
    {
        printf("E");
        if (write(out, &c, 1) == -1)
        {
            
            perror("[write]");
            exit(5);
        }
    } 
    close(*com);  
    close(out);
    close(in);

    return 0;
}
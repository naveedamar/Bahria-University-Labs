// learning from CodeVault Unix Processes in C playlist: https://youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&si=5o1P0_KnWHcd-UKW
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>

#include <time.h>
#include <sys/wait.h>

int main()
{
    // basiclly a space for child and parent process to communicate with each other
    int fd[2];

    /*
    fd[0] -- read
    fd[1] -- write
    */

    if (pipe(fd) == -1)
    {
        printf("Pipe failed.\n");
        return 1;
    }

    int id = fork();
    if (id == -1)
    {
        printf("An error occurred with fork\n");
        return 2;
    }

    if (id == 0)
    {
        /*
        in fds like pipes, we need to close one end to use the other
        since not using read end, we close it in the child process
        */
        close(fd[0]);

        int x;
        printf("Enter a Number: ");
        scanf("%d", &x);

        write(fd[1], &x, sizeof(x));
        close(fd[1]);
    }
    else
    {
        close(fd[1]);

        int y;
        read(fd[0], &y, sizeof(y));
        close(fd[0]);
        
        printf("Number received from child process: %d\n", y);
        wait(NULL);
    }

    return 0;
}
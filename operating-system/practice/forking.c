// learning from CodeVault Unix Processes in C playlist: https://youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&si=5o1P0_KnWHcd-UKW
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>

#include <time.h>
#include <sys/wait.h>

int main()
{

    // forking to create a child process. The child process is an exact copy of the parent process, except for the return value of fork().
    // We can also used getpid() to get the process ID of the current process, and getppid() to get the process ID of the parent process.
    //  int id = fork();

    // child has id = 0
    // if (id != 0)
    // {
    //     fork();
    // }
    // printf("Hello, World! from id = %d\n", id);

    // if(id == 0) {
    //     printf("This is the child process.\n");
    // } else {
    //     printf("This is the parent process.\n");
    // }
    int id = fork();
    int n;

    if (id == 0)
    {
        n = 1;
    }
    else
    {
        n = 6;
    }

    // using wait to ensure that the parent process waits for the child process to finish before it continues executing.
    if (id != 0)
    {
        wait(NULL);
    }

    int i;
    for (i = n; i < n + 5; i++)
    {
        printf("%d ", i);
        // using fflush to ensure that the output is printed immediately, without buffering.
        fflush(stdout);
    }
    if (id != 0)
    {

        printf("\n");
    }

    return 0;
}
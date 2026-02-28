#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>

// required for semctl initialization
union semun
{
    int val;
};

int main()
{

    // creating shared memory for balance
    int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    int *balance = (int *)shmat(shmid, NULL, 0);

    // initializing balance
    *balance = 1000;

    // create semaphore (1 semaphore)
    int semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);

    // initialize semaphore value to 1 (binary semaphore)
    union semun arg;
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);

    // semaphore operations
    struct sembuf lock = {0, -1, 0};  // wait (P)
    struct sembuf unlock = {0, 1, 0}; // signal (V)

    // create 3 child processes (tellers)
    for (int i = 0; i < 3; i++)
    {
        if (fork() == 0)
        {

            // each teller performs 100 deposits of Rs. 10
            for (int j = 0; j < 100; j++)
            {

                semop(semid, &lock, 1); // enter critical section

                *balance += 10; // depositing 10

                semop(semid, &unlock, 1); // exit critical section
            }

            exit(0); // child process exits
        }
    }

    // parent waits for all children
    for (int i = 0; i < 3; i++)
        wait(NULL);

    printf("Final Account Balance: %d\n", *balance);

    // cleanup shared memory and semaphore
    shmdt(balance);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);
}
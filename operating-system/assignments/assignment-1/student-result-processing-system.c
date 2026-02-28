#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>

struct Student
{
    char name[50];
    int marks[3];
};
int main()
{
    // creating a pipe for communication between parent and child
    int fd[2];

    if (pipe(fd) == -1)
    {
        printf("Pipe failed.\n");
        return 1;
    }

    // forking to create a child
    int id = fork();

    if (id == -1)
    {
        printf("An error occurred with fork\n");
        return 2;
    }

    // child process has id = 0
    if (id == 0)
    {
        // closing the read end
        close(fd[0]);

        struct Student s;
        printf("\nStudent Result Processing System\n\n");

        printf("Enter your name: ");
        scanf("%49s", s.name);

        for (int i = 0; i < 3; i++)
        {
            printf("Enter marks for subject %d: ", i + 1);
            scanf("%d", &s.marks[i]);
        }

        write(fd[1], &s, sizeof(s));

        close(fd[1]);
    }
    else
    {

        // closing the write end
        close(fd[1]);

        struct Student s;

        read(fd[0], &s, sizeof(s));

        // calculating total
        int total = 0;
        for (int i = 0; i < 3; i++)
        {
            total += s.marks[i];
        }

        // calculating average
        float average = total / 3.0;

        // calculating grade
        char grade[3];
        if (average >= 85)
            strcpy(grade, "A+");
        else if (average >= 80)
            strcpy(grade, "A");
        else if (average >= 70)
            strcpy(grade, "B");
        else if (average >= 60)
            strcpy(grade, "C");
        else if (average >= 50)
            strcpy(grade, "D");
        else
            strcpy(grade, "F");

        printf("\n");
        printf("Total Marks: %d\n", total);
        printf("Average Marks: %.2f\n", average);
        printf("Grade: %s\n", grade);
        
        //wait for the child process to finish before closing read end 
        wait(NULL);
        
        close(fd[0]);
    }
}

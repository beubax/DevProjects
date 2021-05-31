#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("/test.txt","r");

    while((read = getline(&line, &len, fp))!= -1) {

    pid_t pid1, pid2, pid3;
    int status;
    /* now create new process */
    pid1 = fork();

    if (pid1 >= 0) /* fork succeeded */
    {
        if (pid1 == 0) /* fork() returns 0 for the child process */
        {
            execlp("./Fibb","Fibb",line,NULL);

         }
         else /* parent process */
         {
             printf("Starter[%d] : Forked process with ID %d",getpid(),pid1);
             printf("Waiting for process [%d]", pid1);
             wait(&status); /* wait for child to exit, and store child's exit status */
             printf("Starter: Child process %d returned %d\n", pid1, WEXITSTATUS(status));
             pid2 = fork();

             if (pid2 >= 0) /* fork succeeded */
                    {
                if (pid2 == 0) /* fork() returns 0 for the child process */
                {
                    execlp("./Prime","Prime",line,NULL);

                }
                else /* parent process */
                {
                    printf("Starter[%d] : Forked process with ID %d",getpid(),pid1);
                    printf("Waiting for process [%d]", pid2);
                    wait(&status); /* wait for child to exit, and store child's exit status */
                    printf("Starter: Child process %d returned %d\n", pid2, WEXITSTATUS(status));
                    pid3 = fork();

                    if (pid3 >= 0) /* fork succeeded */
                    {
                        if (pid3 == 0) /* fork() returns 0 for the child process */
                        {
                            execlp("./Total","Total",line,NULL);

                        }
                        else /* parent process */
                        {
                            printf("Starter[%d] : Forked process with ID %d",getpid(),pid1);
                            printf("Waiting for process [%d]", pid3);
                            wait(&status); /* wait for child to exit, and store child's exit status */
                            printf("Starter: Child process %d returned %d \n", pid3, WEXITSTATUS(status));
                            exit(0);}}exit(0);
                            }}

             exit(0);  /* parent exits */
         }


    }
    
    }
}
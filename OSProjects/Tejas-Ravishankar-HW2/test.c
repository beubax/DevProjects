#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2, pid3;
    int status;
    
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char * temp;

   fp = fopen("Test.txt", "r");

while ((read = getline(&line, &len, fp)) != -1) {
    temp = line;
    pid1 = fork();
    if (pid1 >= 0) /* fork succeeded */
    {
        if (pid1 == 0) /* fork() returns 0 for the child process */
        {
            execlp("./Fibb","Fibb",temp,NULL);
         }
         else /* parent process */
         {
             printf("Starter[%d] : Forked process with ID %d\n",getpid(),pid1);
             printf("Waiting for process [%d]\n", pid1);
             wait(&status); /* wait for child to exit, and store child's exit status */
             printf("\nStarter: Child process %d returned %d\n", pid1, WEXITSTATUS(status));
             pid2 = fork();
             if(pid2 >= 0)
             {
                 if (pid2 == 0)
                 {
                     execlp("./Prime","Prime",temp, NULL);
                 }
                 else
                 {
                      printf("Starter[%d] : Forked process with ID %d\n",getpid(),pid2);
                      printf("Waiting for process [%d]\n", pid2);
             wait(&status); /* wait for child to exit, and store child's exit status */
             printf("\nStarter: Child process %d returned %d\n", pid2, WEXITSTATUS(status));                }
             pid3 = fork();
            if(pid3 >= 0)
             {
                 if (pid3 == 0)
                 {
                     execlp("./Total","Total",temp,NULL);
                 }
                 else
                 {
                      printf("Starter[%d] : Forked process with ID %d\n",getpid(),pid3);
                      printf("Waiting for process [%d]\n", pid3);
             wait(&status); /* wait for child to exit, and store child's exit status */
             printf("\nStarter: Child process %d returned %d\n", pid3, WEXITSTATUS(status));
             exit(0);
                 } }
            exit(0);}
             exit(0);
}}}
free(line);
return 0;
}
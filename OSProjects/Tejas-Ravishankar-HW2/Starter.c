#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    pid_t pid1, pid2, pid3;  //variable names for the 3 child processes
    int status;              //for the child to return a value to its parent
    int *fibb,*prime,*total;
    FILE *fp;
    char *line = NULL;       //initialising variables to read lines from .txt file
    size_t len = 0;
    ssize_t read;
    char * temp;

   fp = fopen(argv[1], "r");

while ((read = getline(&line, &len, fp)) != -1) {    //while loop to iterate through each of the lines 
    pid1 = fork();
    if (pid1 >= 0) /* fork succeeded */
    {
        if (pid1 == 0) /* fork() returns 0 for the child process */
        {
            execlp("./Fibb","Fibb",line,NULL);  //Calls the Fibb function
         }
         else /* parent process */
         {
             printf("Starter[%d] : Forked process with ID %d\n",getpid(),pid1);
             printf("Starter[%d] : Waiting for process [%d]\n", getpid(),pid1);
             wait(&status); /* wait for child to exit, and store child's exit status */
             printf("\nStarter: Child process %d returned %d\n", pid1, WEXITSTATUS(status)); //Return from child process
             pid2 = fork();  //Parent forks for 2nd child process
             if(pid2 >= 0)  /* fork succeeded */
             {
                 if (pid2 == 0)  /* fork() returns 0 for the child process */
                 {
                     execlp("./Prime","Prime",line, NULL);  //Calls the Prime function
                 }
                 else   /* parent process */
                 { 
                      printf("Starter[%d] : Forked process with ID %d\n",getpid(),pid2);
                      printf("Starter[%d] : Waiting for process [%d]\n", getpid(), pid2);
             wait(&status); /* wait for child to exit, and store child's exit status */
             printf("\nStarter: Child process %d returned %d\n", pid2, WEXITSTATUS(status)); //Return from child process     
             pid3 = fork();  // Parent forks for 3rd child process
            if(pid3 >= 0)  /* fork succeeded */
             {
                 if (pid3 == 0) /* fork() returns 0 for the child process */
                 {
                     execlp("./Total","Total",line,NULL);
                 }
                 else  
                 {
                      printf("Starter[%d] : Forked process with ID %d\n",getpid(),pid3);
                      printf("Starter[%d] : Waiting for process [%d]\n", getpid(), pid3);
             wait(&status); /* wait for child to exit, and store child's exit status */
             printf("\nStarter: Child process %d returned %d\n", pid3, WEXITSTATUS(status)); //Return from child process
                 } }}}
}}}free(line);
return 0;
}
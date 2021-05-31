#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *temp;

   fp = fopen("Test.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

   while ((read = getline(&line, &len, fp)) != -1) {
        temp = line;
        printf("%s",temp);
    }

   free(line);
}

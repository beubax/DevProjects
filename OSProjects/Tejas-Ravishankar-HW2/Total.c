#include <stdio.h>

int main (int argc, char *argv[]) {
    int k = atoi(argv[1]);
    int i = 1;
    int sum = 0;
    while(i<=k) {
    sum += i;
    i++;
    }
    printf("Total[%d] : Sum = %d",getpid(),sum);
    return sum;
}
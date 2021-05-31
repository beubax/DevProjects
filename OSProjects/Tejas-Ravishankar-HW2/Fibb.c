#include <stdio.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    printf("Fibb[%d] : Number of terms in fibonacii series is %d\n",getpid(),n);
    printf("Fibb[%d] : The first %d numbers of the Fibonacci sequence are:\n",getpid(),n);
    int first = 0;
    int second = 1;
    printf("%d, %d, ",first, second);
    int sum = 0;
    for(int i=3; i<=n; i++) {
        sum = first + second;
        first = second;
        second = sum;
        printf("%d, ",sum);
    }
    return sum;
}
#include <stdio.h>

int main(int argc, char *argv[]) {
    int k = atoi(argv[1]);
    int count = 0, n = 0, i = 1, j = 1;
    printf("Prime[%d] : First prime numbers are:\n",getpid());
    while(n<k)
    {
        j = 1;
        count = 0;
        while(j<=i)
        {
            if(i%j==0) count++;
            j++;
        }
        if(count == 2) 
        {
            printf("%d, ",i);
            n++;
        }
        i++;
    }
    return i-1;
}

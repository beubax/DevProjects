#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int get_iteration_no(int r)
{
return ((r % (100 - 50) + 50));
}

int get_arr_size(int r)
{
   return ((r % (150 - 100) + 100));
} 

char get_arr_val(int r)
{
    int num = ((r % (90 - 64) + 65));
    char character = (char) num;
    return character;
}

float ratio(char *arr, int size, int *maxCount){
    int c = 0, vowel_count = 0, cons_count = 0;
    while(*(arr+c) != '\0') {
        if (*(arr+c) == 'A' || *(arr+c) == 'E' || *(arr+c) == 'I' || *(arr+c)=='O' || *(arr+c) == 'U') 
            vowel_count++;
        else 
            cons_count++;
        c++;
    }
    if(vowel_count>*maxCount) 
        *maxCount = vowel_count;
    // printf("%c\n",*arr);
    return (float) vowel_count/cons_count;
}


float get_running_ratio() {
    int maxCount = 0;
    int maxIteration = 0;
    int maxCountTemp = 0;
    int r = rand();
    int iters = get_iteration_no(r);
    float ratio_sum = 0;
    printf("[Executor]: Number of iterations is %d\n", iters);
    for(int i=1;i<=iters;++i){
        r = rand();
        int arr_size = get_arr_size(r);
        char *p = malloc(sizeof(char)*(arr_size+1));
        for(int j=0;j<arr_size;++j){
            r = rand();
            *(p+j) = get_arr_val(r);
        }
        *(p+arr_size) = '\0';
        maxCountTemp = maxCount;
        ratio_sum += ratio(p, arr_size, &maxCountTemp);
        if(maxCountTemp>maxCount){
            maxIteration = i;
            maxCount = maxCountTemp;
        }
        free(p);
    }
    float avg_ratio = (float) ratio_sum/iters;
    printf("[Executor]: Iteration with maximum vowel count is %d\n", maxIteration);
    return avg_ratio;
}

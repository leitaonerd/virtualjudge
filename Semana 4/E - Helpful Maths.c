#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b){
    return(*(int*)a - *(int*)b);
}

int main(){

    char string[101];
    int nums[52], count = 0;

    scanf("%s", string);
    for(int i = 0; i < strlen(string); i++){
        if(string[i] >= '0' && string[i] <= '9'){
            nums[count] = string[i] - '0';
            count++;
        }
    }
    qsort(nums, count, sizeof(int), compare);
    for(int i = 0; i < count-1; i++){
        printf("%d+", nums[i]);
    }
    printf("%d\n", nums[count-1]);

    return 0;
}
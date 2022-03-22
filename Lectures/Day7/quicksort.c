#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* num1, const void* num2){
    return (fabs(*(int*)num1 % 10)) - (fabs(*(int*)num2 % 10));
}

int main(){
    int nums[] = {103, 203, -4, 534, 18, 90, -1};
    qsort(nums, 7, sizeof(nums[0]), compare);
    for (int i = 0; i < 7; i++){
        printf("%d ", nums[i]);
    }
    putchar('\n');
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArr(int* arr, int n){
    int i = 0;
    printf("Length: %d arr=[", n);
    while(i < n){
        printf("%d ", arr[i]);
        i++;
    }
    printf("]\n");
}

int main(){
    int nums[] = {20, 30, 40};
    int nums2[10];
    memmove(nums2, nums, 12);
    printArr(nums2, 3);
    return 0;
}
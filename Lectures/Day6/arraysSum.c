#include <stdio.h>
#define COUNT 5

int sumArr(int* arr, int n) { //int* arr
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += *(arr + i);
    }
    return sum;
}

int maxNum(int* arr, size_t n){
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){ // max = (arr[i] > max) ? arr[i] : max;
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int nums[COUNT];
    printf("Sum = %d\n", sumArr(nums, COUNT));
}
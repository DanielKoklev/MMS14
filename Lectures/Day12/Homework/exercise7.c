#include <stdio.h>

unsigned int BinSearch(unsigned int *pArray, unsigned int uArraySize, unsigned int uValue){
    int left = 0;
    int right = uArraySize - 1;

    while(left <= right){
        int middle = left + (right - 1) / 2;
        if(pArray[middle] == uValue){
            return middle;
        }
        if(pArray[middle] < uValue){
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 40;
    int result = BinSearch(arr, n, x);
    if(result == -1){
        printf("%d", result);
    } else {
        printf("%x", 0xFFFF);
    }
    return 0;
}
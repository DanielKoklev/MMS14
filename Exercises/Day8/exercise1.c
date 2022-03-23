#include <stdio.h>

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
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printArr(arr1, 10);
}
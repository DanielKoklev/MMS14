#include <stdio.h>
void printArr(int*,int);
void inputIntArray(int*,int);

void bubbleSort(int* arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n - i; j++){
            if(arr[j-1] > arr[j]){ //change '>' to '<' to sort it backwards
                int c = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = c;
            }
        }
    }
}


int main(){
    int arr1[100];
    inputIntArray(arr1, 10);
    bubbleSort(arr1, 10);
    printArr(arr1, 10);
}

void printArr(int* arr, int n){
    int i = 0;
    printf("Length: %d arr=[", n);
    while(i < n){
        printf("%d ", arr[i]);
        i++;
    }
    printf("]\n");
}

void inputIntArray(int* arr, int n){
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
}

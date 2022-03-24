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

void inputIntArray(int* arr, int n){
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
}

void myMap(int* arr, int n, int (*f)(int)){
    for(int i = 0; i < n; i++){
        arr[i] = f(arr[i]);
    }
}

int square(int a){
    return a*a;
}

int main(){
    int arr[100];
    inputIntArray(arr, 10);
    myMap(arr, 10, square);
    printArr(arr, 10);
    return 0;
}
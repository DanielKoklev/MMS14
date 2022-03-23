#include <stdio.h>

void inputIntArray(int* arr, int n){
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
}

int main(){
    int arr[10];
    inputIntArray(arr, 10);
}
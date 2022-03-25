#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int isOdd(int n){
    return n&1;
}

int is2sPower(int n){
    int i = 1;
    while(i < n){
        i <<= 1;
    }
    return i==n;
}

int isEven(int n){
    return !(n&1);
}
//int* myFilter(int* arr, int(*filterFunction)(int));

void myFilter(int* arr, int(*filterFunction)(int)){
    int n=0;
    for(int i = 0; arr[i] != 0 ;i++){
        if(filterFunction(arr[i])) {
            n++;
        }
    }
    int* res = malloc(n*sizeof(int));
    
    for(int i = 0; arr[i] != 0 ;i++){
        if(filterFunction(arr[i])) {
            n++;
        }
    }
}

int main(){
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    myFilter(arr1, isEven);
    printf("\n");
    myFilter(arr1, isOdd);
    printf("\n");
    myFilter(arr1, is2sPower);
    return 0;
}
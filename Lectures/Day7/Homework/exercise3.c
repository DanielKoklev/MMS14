#include <stdio.h>
#include <stdlib.h>


int sumArr(int*,int);

void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int)){

}

int main(){
    int(*f)(int*,int) = sumArr;
    int arr[] = {1, 2, 3};
    arrayEvaluate(arr, 3, sumArr);
    return 0;
}

int sumArr(int* arr, int n) { 
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += *(arr + i);
    }
    return sum;
}

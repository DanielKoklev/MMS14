#include <stdio.h>

double averageNum(int*,size_t);
int minNum(int*,size_t);


int main(){
    int nums[] = {2, 4 ,5, 1, 6};

    printf("Min number: %d\n", minNum(nums, 5));
    printf("Average: %.2lf\n", averageNum(nums, 5));

}

int minNum(int* arr, size_t n){
    int min = *arr;
    for(int i = 1; i < n; i++){
        min = (*(arr + i) < min) ? *(arr + i) : min;
    }
    return min;
}

double averageNum(int* arr, size_t n){
    int sum = 0;
    double average = 0;
    for(int i = 0; i < n; i++){
        sum += *(arr + i);
    }
    average = (double)sum / n;
    return average;
}
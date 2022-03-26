#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cnt 10

int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

void swapg(void* a, void* b, size_t size){
    char temp[size];
    memmove(temp, a, size);
    memmove(a, b, size);
    memmove(b, temp, size);
}

void bubbleSort(void* arr, size_t n, size_t size, int (*comp)(const void*,const void*)){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < (n-i-1) * size; j+= size){
            if (comp(arr + j, arr + j + size) > 0){
                swapg(arr + j, arr + j + size, size);
            }
        }
    }
}


void (*getSorting(char* fname))(void*,size_t,size_t,int(*)(const void*,const void*)){
    if(fname == "qsort"){
        return qsort;
    } else if (fname == "bubble Sort"){
        return bubbleSort;
    }
}


void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main(){
    int arr[cnt] = {34, 53, 75, 87, 33, 11, 23, 56, 96, 213}; 
    //getSorting("bubble Sort")(arr, cnt, sizeof(int), compare);
    getSorting("qsort")(arr, cnt, sizeof(int), compare);
    printArray(arr, cnt);
    return 0;
}
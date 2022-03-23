#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define COUNT 20

// void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
// void bubbleSort(void* arr, size_t n, size_t size, int (*comp)(const void*,const void*))
int compare(const void* a, const void* b){
    return *(int*)b - *(int*)a;
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
            if (comp(arr + j, arr + j + size) < 0){
                swapg(arr + j, arr + j + size, size);
            }
        }
    }
}


void *linearSearch(const void* key,void* arr, size_t n, size_t size, int (*comp)(const void*, const void*)){
    for(int i = 0; i < n*size; i+= size){
        if(comp((arr + i), key) == 0){
            return arr + i;
        }
    }
    return NULL;
}


int main(){
    /*char num1 = 'z', num2 = 'a';
    swapg(&num1, &num2, sizeof(char));
    printf("%c %c\n", num1, num2);*/
    srand(time(NULL));
    int arr[COUNT];
    int arr2[12] = {43, 53, 65, 348, 235, 765, 7754, 123, 4324, 53, 1, 34};
    int key = 53;

    for (int i = 0; i < COUNT; i++){
        arr[i] = rand() % 100;  // 0-99
    }
   // qsort(arr, COUNT, sizeof(int), compare);
    bubbleSort(arr2, COUNT, sizeof(int), compare);
    for (int i = 0; i < COUNT; i++){
        printf("%d ", arr2[i]);
    }
    putchar('\n');

    int *element = linearSearch(&key, arr2, 12, sizeof(int), compare);
    if(element == NULL){

    }else {
        printf("%d\n", *element);
    }
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    size_t max_size, length;
}myDynamicArray;

myDynamicArray createDynamicArray(size_t initial_max_size);
void push(myDynamicArray *dArr, int newEl);
int pop(myDynamicArray*);
void myPrint(myDynamicArray*);

int main(){

    myDynamicArray dArr1 = createDynamicArray(100);
    push(&dArr1, 100);
    push(&dArr1, 200);
    push(&dArr1, 300);
    push(&dArr1, 400);
    push(&dArr1, 500);
    push(&dArr1, 600);
    pop(&dArr1);
    pop(&dArr1);
    push(&dArr1, 700);
    push(&dArr1, 800);
    myPrint(&dArr1);
    free(dArr1.arr);

    return 0;
}

myDynamicArray createDynamicArray(size_t initial_max_size){
    int arr[initial_max_size];
    myDynamicArray newDynamicArray;
    newDynamicArray.max_size = initial_max_size;
    newDynamicArray.length = 0;
    newDynamicArray.arr = (int*)malloc(sizeof(int)*initial_max_size);
    if(!newDynamicArray.arr){
        fprintf(stderr, "Malloc failed\n");
        exit(-1);
    }
    return newDynamicArray;
}

void push(myDynamicArray *dArr, int newEl){
    if(dArr->length == dArr->max_size){
        size_t newMaxSize = dArr->max_size * 2;
        dArr->arr = (int*)realloc(dArr->arr, newMaxSize*sizeof(int));
        dArr->max_size = newMaxSize;
        if(!dArr->arr){
            fprintf(stderr, "Realloc failed\n");
        }
    }
    dArr->arr[dArr->length++] = newEl;
    printf("PUSH\n");
    myPrint(dArr);
}

void myPrint(myDynamicArray* dArr){
    printf("max_size: %lu; length: %lu\n", dArr->max_size, dArr->length);
    for(int i = 0; i < dArr->length; i++){
        printf("%d ", dArr->arr[i]);
    }
    printf("\n\n");
}

int pop(myDynamicArray* dArr){
    if(dArr->length == 0){
        fprintf(stderr, "Dynamic array is empty\n");
        exit(-1);
    }
    //if(dArr->max_size == dArr->length)
    printf("POP\n");
    myPrint(dArr);
    return dArr->arr[--dArr->length];
}

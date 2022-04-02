#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* arr;
    size_t max_size, length;
}myDynamicArray;

myDynamicArray createDynamicArray(size_t initial_max_size);
void push(myDynamicArray *dArr, char newEl);
char pop(myDynamicArray*);
void myPrint(myDynamicArray*);
char getLast(myDynamicArray* dArr);

int main(){

    myDynamicArray bracketsStack = createDynamicArray(4);
    char input[1000];
    scanf("%s", input);
    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] == '(' || input[i] == '[' || input[i] == '{' || input[i] == '<'){
            push(&bracketsStack, input[i]);
        } else{
            if(bracketsStack.length == 0){
                printf("NO - empty stack / too many closing brackets\n");
                free(bracketsStack.arr);
                exit(-1);
            }
            char c = input[i], o = getLast(&bracketsStack);
            //printf("opening: %c closing: %c\n", o, c);
            if((o == '(' && c == ')') ||
                (o == '[' && c == ']') ||
                (o == '{' && c == '}') ||
                (o == '<' && c == '>')) {
                    pop(&bracketsStack);
                } else {
                    printf("NO - brackets are not maching\n");
                    free(bracketsStack.arr);
                    exit(-1);
                }
            
        }
    }
    if(bracketsStack.length > 0){
        printf("NO - too many opening brackets\n");
    } else {
        printf("YES\n");
    }
    free(bracketsStack.arr);  
    return 0;
}

myDynamicArray createDynamicArray(size_t initial_max_size){
    int arr[initial_max_size];
    myDynamicArray newDynamicArray;
    newDynamicArray.max_size = initial_max_size;
    newDynamicArray.length = 0;
    newDynamicArray.arr = (char*)malloc(sizeof(char)*initial_max_size);
    if(!newDynamicArray.arr){
        fprintf(stderr, "Malloc failed\n");
        exit(-1);
    }
    return newDynamicArray;
}

void push(myDynamicArray *dArr, char newEl){
    if(dArr->length == dArr->max_size){
        size_t newMaxSize = dArr->max_size * 2;
        dArr->arr = (char*)realloc(dArr->arr, newMaxSize*sizeof(char));
        dArr->max_size = newMaxSize;
        if(!dArr->arr){
            fprintf(stderr, "Realloc failed\n");
        }
    }
    dArr->arr[dArr->length++] = newEl;
    //printf("PUSH\n");
}

void myPrint(myDynamicArray* dArr){
    //printf("max_size: %lu; length: %lu\n", dArr->max_size, dArr->length);
    for(int i = 0; i < dArr->length; i++){
        printf("%c ", dArr->arr[i]);
    }
    printf("\n\n");
}

char pop(myDynamicArray* dArr){
    if(dArr->length == 0){
        fprintf(stderr, "Dynamic array is empty\n");
        exit(-1);
    }
    //if(dArr->max_size == dArr->length)
    //printf("POP\n");
    myPrint(dArr);
    return dArr->arr[--dArr->length];
}

char getLast(myDynamicArray* dArr){
    //char res = *(dArr->arr + dArr->length-1);
    //char res = dArr->arr[dArr->length - 1];
    return dArr->arr[dArr->length - 1];
}

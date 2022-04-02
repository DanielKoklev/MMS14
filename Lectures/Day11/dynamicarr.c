#include <stdio.h>
#include <stdlib.h>



int main(){
    int num;
    scanf("%d", &num);

    int* arr = malloc(sizeof(int) * num);
    for(int i = 0; i < num; i++){
        arr[i] = i;
    }
    for(int i = 0; i < num; i++){
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr);
    return 0;
}
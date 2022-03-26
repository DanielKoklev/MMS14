#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define cnt 10

int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int binarySearch(int* array, size_t n, int key){
    int startIndex = array[0];
    int endIndex = n - 1;
    while(startIndex <= endIndex){
        int mid = startIndex + (endIndex - startIndex) / 2;
        if(array[mid] == key){
            return mid;
        } else if(array[mid] < key){
            startIndex = mid + 1;
        } else {
            endIndex = mid - 1;
        }
    }
    return -1;
}



int main(){
    int arr[cnt] = {5, 7 , 32, 75, 773, 64, 21, 65, 90, 84};
    int key = 90;
    qsort(arr, cnt, sizeof(int), compare);
    for (int i = 0; i < cnt; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');

    int foundKey = binarySearch(arr, cnt, key);
    if (foundKey == -1){
        printf("Key is not found in the array!");
    } else {
        printf("Element found at index: %d\n", foundKey);
    }

    return 0;
}
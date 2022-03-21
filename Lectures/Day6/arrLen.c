#include <stdio.h>

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]); // length of the array
    printf("%lu\n", n);
    return 0;
}
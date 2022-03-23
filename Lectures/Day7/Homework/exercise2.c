#include <stdio.h>
// can't finish the exercise
unsigned sumArrayDigits(const int* arr, size_t n){
    int sum = 0;
 
    for(int i = 0; i < n; i++){
        int x = arr[i];
        while(x){
            sum += x % 10;
            x /= 10;
        }
    }
    return sum;
}



int main(){
    int arr[] = {12, 34, 5, 70};
    int sum = sumArrayDigits(arr, 4);
    printf("Sum of the array digits is: %d\n", sum);
    return 0;
}
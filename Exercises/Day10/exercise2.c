#include <stdio.h>

int sumDigits(int n){
    if(n < 10){
        return n;
    }
    return n % 10 + sumDigits(n / 10);
}

int main(){
    printf("%d\n", sumDigits(12345));
    return 0;
}
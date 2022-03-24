#include <stdio.h>

unsigned factorial(unsigned n){
    if (n==0){
        return 1;
    }
    return factorial(n-1)*n;
}

int main(){
    printf("%u\n", factorial(6));
    return 0;
}
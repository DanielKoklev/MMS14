#include <stdio.h>

int main(){
    unsigned N, M;
    scanf("%d %d", &N, &M);
    printf("N/2^M=%d\n", N>>M);
    int remMask = ((1<<M) - 1);
    printf("N mod M=%d\n", N & remMask);
}
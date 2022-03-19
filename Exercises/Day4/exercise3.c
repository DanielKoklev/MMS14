#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    // bitwise shift = multiplication (n x 2, n x 4, n x 8...)
    int result = (n << 3) - n;
    
    printf("%d\n", result);

    return 0;
}
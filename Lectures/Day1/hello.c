#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num1, num2, result;
    scanf("%d", &num1);
    scanf("%d", &num2);
    result = sqrt(num1 + num2);
    printf("%d", result);
    return EXIT_SUCCESS;
}


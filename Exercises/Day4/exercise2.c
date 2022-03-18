#include <stdio.h>

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    int result = (a ^ b) < 0;
    printf("%d\n", result);
}
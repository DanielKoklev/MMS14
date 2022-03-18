#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if (!a&&b || a&&!b || !c&&a || c&&!b) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    // ./exercise2 <  numbers2.txt 
}
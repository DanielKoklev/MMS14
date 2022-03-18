#include <stdio.h>

int main() {
    int num1, num2;
    double rNum;
    int n = scanf("%d %d %lf", &num1, &num2, &rNum); //returns the number of successfull inputs
    printf("n = %d\n", n );
    return 0;
}
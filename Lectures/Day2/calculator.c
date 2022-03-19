#include <stdio.h>

int main()
{
    double num1, num2;
    char op;
    scanf("%lf %c %lf", &num1, &op, &num2);

    if (op == '+'){
        printf("%.2lf\n", num1 + num2);
    } else if (op == '-') {
        printf("%.2lf\n", num1 - num2);
    } else if (op == '/') {
        printf("%.2lf\n", num1 / num2);
    } else if (op == 'x') {
        printf("%.2lf\n", num1 * num2);
    } else {
        fprintf(stderr, "Invalid operation!\n");
        return 1;
    }
    return 0;
    
}
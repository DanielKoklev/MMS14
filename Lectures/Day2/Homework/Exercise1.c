#include <stdio.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("%lf\n%lf\n%lf\n", a, b, c);
    // ./exercise1 < numbers1.txt | sort -n | tail -1
}
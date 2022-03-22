#include <stdio.h>

double sum(double a, double b){
    return a + b;
}
double sub(double a, double b){
    return a - b;
}
double mul(double a, double b){
    return a * b;
}
double div(double a, double b){
    return a / b;
}

int main(){
    double (*fcalc[4])(double,double) = { sum, sub, mul, div};
    int n;
    do{
        scanf("%d", &n);
    } while(n < 0 || n > 3);
    double result = fcalc[3](10, 20);
    printf("Result = %.lf\n", result);
    return 0;
}
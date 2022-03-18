#include <stdio.h>
#include <math.h>

// comparing with "==" operator
int compare1(double a, double b){
        return a == b;
    }

// comparing with pre-defined epsilon
int compare2(double a, double b){
    return fabs(a - b) < __FLT_EPSILON__;
}

// comparing with dynamic epsilon
int compare3(double a, double b){
    return fabs(a - b) < __FLT_EPSILON__ * fmax(fabs(a), fabs(b));
}

int main() {
    double a = 1.1;
    double b = 0;

    for (int i = 0; i < 11; i++) {
        b += 0.1;
    }
    if(compare1(a, b)){
        printf("a == b\n");
    } else {
        printf("a != b\n");
    }

    if(compare2(a, b)){
        printf("built-in epsilon - equals\n");
    } else {
        printf("built-in epsilon - not equals\n");
    }

    if(compare3(a, b)){
        printf("dynamic epsilon - equals\n");
    } else {
        printf("dynamic epsilon - not equals\n");
    }

    return 0;
}
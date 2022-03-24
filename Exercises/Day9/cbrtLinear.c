#include <stdio.h>

int main(){
    double n;
    scanf("%lf", &n);
    double lo = 0.0000, hi = n;
    for(double i = lo; i < hi; i+= 0.0001){
        printf("i=%lf  i*i*i=%lf\n", i, i*i*i);
        if(i*i*i >= n){
            printf("CBRT(%lf)=%lf\n", n, i);
            return 0;
        }
    }
}
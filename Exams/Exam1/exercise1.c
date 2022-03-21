#include <stdio.h>
#include <math.h>

int cylinder(double,double,double*,double*);


int main() {
    double r, h, V, S;
    while(scanf("%lf %lf", &r, &h) != EOF){
        if(cylinder(r, h, &V, &S) == -1){
            printf("Invalid data\n");
        } else {
            printf("V = %.2lf, S = %.2lf\n", V, S);
        }
    }

}



int cylinder(double r, double h, double* V, double* S){
    if(r <= 0 || h <= 0){
        return -1;
    }
    double area = M_PI * pow(r, 2);
    *S = 2 * M_PI * r * (r + h);
    *V = area * h;
    return 0;

}
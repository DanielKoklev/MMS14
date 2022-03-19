#include <stdio.h>

int rectangle(double,double,double*,double*);

int main(){
    double w, h, per, area;
    while(scanf("%lf %lf", &w, &h) != EOF){
        if (rectangle(w, h, &per, &area) == -1) {
            printf("Invalid sides\n");
        } else {
            printf("P = %.2lf, S = %.2lf\n", per, area);
        }
        
    }
}


int rectangle(double w, double h, double* P, double* S){
    if(w <= 0 || h <= 0){
        return -1;
    }
    *P = 2 * (w + h);
    *S = w * h;
    return 0;
}
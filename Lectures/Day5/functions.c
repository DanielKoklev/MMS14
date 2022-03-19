#include <stdio.h>

void sayHello();
int getNum();
int sum(int num1, int num2);
double max(double, double);
int setZero(int*);
void swapNums(int*,int*);
void setValues(int*,double*);
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


void sayHello(){
    printf("Hello\n");
}

int getNum(){
    return 100;
}

int sum(int num1, int num2){
    return num1 + num2;
}

double max(double num1, double num2){
    if(num1 > num2){
        return num1;
    }
    return num2;
}

int setZero(int* num){
    *num = 0;
}

void swapNums(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void setValues(int* num1, double* num2){
    *num1 = 180;
    *num2 = 3.14;
}

int rectangle(double w, double h, double* P, double* S){
    if(w <= 0 || h <= 0){
        return -1;
    }
    *P = 2 * (w + h);
    *S = w * h;
    return 0;
}
#include <stdio.h>
#include <stdarg.h>

#define TINT 1
#define TDOUBLE 2
#define TCHAR 3

int sumNums(int count, ...){
    int sum = 0;
    va_list ap;
    va_start(ap, count);
    for(int i = 0; i < count; i++){
        sum += va_arg(ap, int);
    }
    va_end(ap);
    return sum;
}

double average(int count, ...){
    double sum = 0;

    va_list args;
    va_start(args, count);

    for(int i = 0; i < count; i++){
        sum += va_arg(args, double);
    }
    va_end(args);
    return sum / count;

}

// type: 1->int, 2-> double, 3->char
void printNums(int type, int count, ...){
    va_list args;
    va_start(args, count);
    for(int i = 0; i < count; i++) {
        if(type == 1){
            int num = va_arg(args, int);
            printf("%d ", num);
        } else if (type == 2) {
            double num = va_arg(args, double);
            printf("%lf ", num);
        } else if (type == 3) {
            int num = va_arg(args, int);
            printf("%c ", num);
        }
    }
    va_end(args);
    printf("\n");
}


int main(){
    //int result = sumNums(3, 10, 3 ,5);
    //printf("Result = %d\n", result);
    printNums(TINT, 3, 10, 20, 30);
    return 0;
}
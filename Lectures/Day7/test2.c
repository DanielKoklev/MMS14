#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int myatoi(const char* str){
    int num = 0;
    int multiplier = 1;
    if(*str == '-'){
        multiplier = -1;
        for(int i = strlen(str) - 1, n = 1; i > 0; i--, n *= 10){
            num += n * (str[i] - '0');
        }
    } else {
        for(int i = strlen(str) - 1, n = 1; i >= 0; i--, n *= 10){
            num += n * (str[i] - '0');
        }
    }
    return num * multiplier;
}

int main(){
    /*char str[100];
    strcpy(str, "205");
    int num = atoi(str);
    printf("Num = %d\n", num);
    strcpy(str, "-35.5");
    double realNum = atof(str);
    printf("Real num = %lf\n", realNum);*/

    /*char str[100];
    strcpy(str, "fa3 3.14");
    int num;
    double pi;
    sscanf(str, "%x %lf", &num, &pi);
    printf("Num = %d %lf\n", num, pi);*/

    char str[10];
    strcpy(str, "203");
    int num = myatoi(str);
    printf("Number: %d\n", num);

    return 0;
}
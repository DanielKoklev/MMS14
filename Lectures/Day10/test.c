#include <stdio.h>

void printValue1(double n){
    printf("Num = %.1lf\n", n);
}

void printValue2(double n){
    printf("Num = %.2lf\n", n);
}

void (*getFunc(int a))(double){
    if (a==1){
        return printValue1;
    } else{
        return printValue2;
    }
}

functionPtr getFunc(int a){
    if (a==1){
        return printValue1;
    } else{
        return printValue2;
    }
}

/*void callFunc(int n, void (*fp)(double)){
    if(n == 1){
        fp(4.5);
    } else {
        fp(-4.5);
    }
}*/

void callFunc(int n, functionPtr fp2){
    if(n == 1){
        fp(4.5);
    } else {
        fp(-4.5);
    }
}

typedef void(*functionPtr)(double);

int main(){
    void(*fp1)(double);
    functionPtr fp2;
    fp2 = printValue1;

    void (*fp)(double) = getFunc(2); // first option
    getFunc(2)(2.4); // second option
    fp(4.5);
    /*void (*fp)(double);
    fp = printValue;
    fp(4.20);
    printf("%p\n", fp);*/
    //callFunc(1, printValue1);
    return 0;
}
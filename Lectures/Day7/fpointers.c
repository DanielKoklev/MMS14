#include <stdio.h>

int sum(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}



int main(){
    int (*fp)(int,int);
    fp = sum;

    int num = fp(10, 20);
    printf("%d\n", num);

    fp = sub;
    num = fp(10, 20);
    printf("%d\n", num);
    return 0;
}
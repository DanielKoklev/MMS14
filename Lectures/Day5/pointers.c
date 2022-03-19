#include <stdio.h>

int main(){
    int num = 20;
    int *ptr = &num;
    printf("Address of num: %p\n", ptr);
    printf("Address of num: %d\n", *ptr);
}
#include <stdio.h>
#include <stdarg.h>

// can't finish the exercise yet

unsigned onesCount(unsigned count, size_t size, ...){
    va_list args;
    int cntr = 0;
    va_start(args, size);
    unsigned number = va_arg(args, unsigned);
    
    while(number > count){
        cntr += number & 1;
        number >>= 1;
    }
    printf("%d\n", number);


}

int main(){

    onesCount(2, 1, 3, 2);
    return 0;

}
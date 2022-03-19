#include <stdio.h>
#include <stdarg.h>
#include <math.h>

unsigned onesCount(unsigned count, size_t size, ...){
    va_list args;
    unsigned cntr = 0;
    va_start(args, size);
    unsigned num = va_arg(args, unsigned);

    for(int i = 0; i < count; i++){
        unsigned num = va_arg(args, unsigned);
        cntr += num & 1;
        num >>= 1;
        printf("%u\n", num);
    }
    va_end(args);

    return cntr;

}

int main(){

    onesCount(1, 1, 3);
    return 0;

}
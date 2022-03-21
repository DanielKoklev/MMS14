#include <stdio.h>
#include <stdarg.h>

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...){
    va_list args;
    int cntr = 0;
    va_start(args, bitscnt);
    
    unsigned num = va_arg(args, unsigned);
    for(int i = 0; i < count; i++){

        cntr += num & 1;
        num >>= 1;
        if(num == bitscnt){
            printf("%d\n", num);
        }
    }
}


int main(){

    bitsNCount(4, 2, 0x0a, 0xff, 0, 1);
    return 0;

}
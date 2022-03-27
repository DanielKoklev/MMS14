#include <stdio.h>
#include <stdint.h>

void swapBytes(uint16_t* num){
    uintptr_t x = *num;
    x = ((*num << 8) & 0xff00) | ((*num >> 8) & 0x00ff);
    printf("%lu\n", x);
    
}

int main()
{
    uint16_t number = 54328;

    swapBytes(&number);
    

    

    return 0;
}
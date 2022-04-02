#include <stdio.h>
#include <stdint.h>



void swapBytes(uint16_t* word){
    uint16_t x = *word;
    uint16_t high = (x & 0xff00);
    uint16_t low = (x & 0xff);

    uint16_t y = (low << 8);
    y |= (high >> 8);
}

int main(){
    swapBytes(0x1f12);
    return 0;
}
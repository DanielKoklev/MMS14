#include <stdio.h>
#include <stdint.h>

<<<<<<< HEAD


void swapBytes(uint16_t* word){
    uint16_t x = *word;
    uint16_t high = (x & 0xff00);
    uint16_t low = (x & 0xff);

    uint16_t y = (low << 8);
    y |= (high >> 8);
}

int main(){
    swapBytes(0x1f12);
=======
void swapBytes(uint16_t* num){
    uintptr_t x = *num;
    x = ((*num << 8) & 0xff00) | ((*num >> 8) & 0x00ff);
    printf("%lu\n", x);
    
}

int main()
{
    uint16_t number = 54328;

    swapBytes(&number);
    

    

>>>>>>> c6239a570b22acdda0fb82a69941b0a6df92b355
    return 0;
}
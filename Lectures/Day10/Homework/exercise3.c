#include <stdio.h>
#include <stdint.h>
// unfinished
int clearBit(uint32_t* maskArr, size_t nitems, size_t bit);
int setBit(uint32_t* maskArr, size_t nitems, size_t bit);
int checkBit(uint32_t* maskArr, size_t len, size_t bit);


int main(){

    return 0;
}


int checkBit(uint32_t* maskArr, size_t len, size_t bit){
    return !!(*maskArr & (1 << bit));
}
#include <stdio.h>

#define SETBIT(mask, bit) (mask |= (1 << (bit)))
#define CLEARBIT(mask, bit) (mask &= ~(1 << (bit)))
#define CHECKBIT(mask, bit) (!!(mask & (1 << (bit))))
#define CHANGEBIT(mask, bit) (mask ^= (1 << (bit)))

int main(){

    return 0;
}
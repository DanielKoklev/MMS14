#include <stdio.h>
#include <stdint.h>

int checkBit(uint32_t mask, unsigned bit) {
    return !!(mask & (1 << bit));
}

void setBitP(uint32_t* ptr, unsigned bit){
    *ptr |= (1 << bit);
}

/*uint32_t setBit(uint32_t mask, unsigned bit){
    return mask | (1 << bit);
}*/

int main() {
    uint32_t mask = 0x00;

    setBitP(&mask, 2);

    for (int i = sizeof(uint32_t) * 8; i >= 0; i--) {
        printf("%d", checkBit(mask, i));
    }
    printf("\n");
    // printf("Check: %d\n", checkBit(mask, 5));

}
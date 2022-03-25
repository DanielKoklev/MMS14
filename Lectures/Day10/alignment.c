#include <stdio.h>
#include <stdint.h>
struct str_a {
    unsigned a : 3; //bit-field
    unsigned b : 2;
};

struct counters {unsigned
    short cnt1 : 5; //bit-field
    short cnt2 : 5;
    short cnt3 : 5;
};

typedef union {
    uint8_t byte;
    struct {
        uint8_t bit0 : 1;
        uint8_t bit1 : 1;
        uint8_t bit2 : 1;
        uint8_t bit3 : 1;
        uint8_t bit4 : 1;
        uint8_t bit5 : 1;
        uint8_t bit6 : 1;
        uint8_t bit7 : 1;
        
    };
} REG;



int main(){
    /*union A un;
    un.num = 0x0100;

    if(un.byte[0] == 0x00){
        printf("Little endian!\n");
    } else if (un.byte[0] == 0x01){
        printf("Big endian!\n");
    }
    printf("%lu\n", sizeof(struct str_a));
    struct str_a bf;
    bf.a = 0;
    for(int i = 0; i < 10; i++){
        printf("%u ", bf.a);
        bf.a++;
    }
    putchar('\n');*/

    REG myreg;
    myreg.byte = 0xff;
    myreg.bit7 = 0;
    myreg.bit1 = 0;
    printf("%x\n", myreg.byte);

    return 0;
}

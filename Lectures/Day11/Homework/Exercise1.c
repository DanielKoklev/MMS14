#include <stdio.h>
#define MAX(x,y,z) ((x)>(y)?((x)>(z)?(x):(z)):((y)>(z)?(y):(z)))
#define MIN(x,y,z) ((x)<(y)?((x)<(z)?(x):(z)):((y)<(z)?(y):(z)))
#define SETBIT(mask, bit) (mask |= (1 << (bit)))
#define CLEARBIT(mask, bit) (mask &= ~(1 << (bit)))
#define CHECKBIT(mask, bit) (!!(mask & (1 << (bit))))
#define INVERSEBIT(mask, bit) (mask ^= (1 << (bit)))
#define SWAP(a,b) (int temp; (a) = temp; (b) = (a); temp = (b);)

int main(){
    int a = 5, b = 3, c = 7;
    int d = MIN(a, b, c);
    printf("%d\n", d);
}
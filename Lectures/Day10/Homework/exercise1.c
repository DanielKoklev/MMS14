#include<stdio.h>
#include <stdint.h>

void bitRepresent(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}
 
int main(void)
{
    bitRepresent(50.564);
    printf("\n");

}
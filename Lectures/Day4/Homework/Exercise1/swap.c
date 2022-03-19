void swap(int* num1, int* num2)
{
    *num1 ^= *num2;
    *num2 ^= *num1;
    *num1 ^= *num2;
}

// gcc -E swap.c -o swap.i
// gcc -S swap.i -o swap.s
// gcc -c swap.s -o swap.o
// gcc program.o swap.o -o swapNums
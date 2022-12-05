#include <stdio.h>

int bitcount(unsigned anInt);

int main(void)
{
    fprintf(stdout, "1 bits in 0%o: %d\n", 0777, bitcount(0777));
    fprintf(stdout, "1 bits in 0x%x: %d\n", 0xff, bitcount(0xff));

    return 0;
}

// Count 1-bits in num.
int bitcount(unsigned num)
{
    int b;
    for (b = 0; num != 0; num >>= 1)
        if (num & 01)
            b++;

    return b;
}


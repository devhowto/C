// Exercise 2-9. In a two's complement number system, x &= (x - 1) deletes the
// rightmost 1-bit in x. Explain why. Use this observation to write a faster
// version of bitcount.

// When we subtract 1 from a number, it will produce a binary that has a
// zero in the place where the rightmost 1-bit was. The & operation
// will make that bit become zero.

#include <stdio.h>

int bitcount(unsigned num);

int main(void)
{
    fprintf(stdout, "1 bits in 0%o: %d\n", 0777, bitcount(0777));
    fprintf(stdout, "1 bits in 0x%x: %d\n", 0xff, bitcount(0xff));

    return 0;
}

// Count 1-bits in num.
int bitcount(unsigned num)
{
    int count = 0;
    //for (b = 0; num != 0; num >>= 1)
    //    if (num & 01)
    //        b++;

    // Faster:
    // - will reach zero sooner;
    // - subtraction shifts less bits and than >> (which shifts
    //   everything to the right;
    // - we avoided the if;
    while (num != 0) {
        count += 1;
        num &= (num - 1);
    }

    return count;
}


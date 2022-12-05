// Exercise 2-7. Write a function invert(num, pos, len) that returns num with
// the len bits that begin at position pos inverted (i.e., 1 changed into 0 and
// vice versa), leaving the others unchanged.

#include <stdio.h>

unsigned invert(unsigned num, int pos, int len);

int main(void)
{
    printf("invert(%u, %d, %d) => %u\n", 213, 3, 2, invert(213, 3, 2));


    return 0;
}

unsigned invert(unsigned num, int pos, int len)
{
    // 8-bit numbers, pos = 3, len = 2:
    // replacemnt will be 1111 0011 (all positions set to 1, except
    // for the ones in which num will be inverted.
    unsigned replacement = (~0 << (pos + 1)) | ~(~0 << (pos + 1 - len));

    // Create a number from num's complement with everything set to
    // 0 except for the digits to be inverted in num.
    unsigned inverter = ~num & ~replacement;

    // Now we turn the bits to be inverted in num to 0, and then run
    // an | operation to produce the final result.
    return (num & replacement) | inverter;
}

/*

pos = 3
len = 2

     ..
1101 0101  → 213
     ^
     ..
1101 1001  → 217


*/

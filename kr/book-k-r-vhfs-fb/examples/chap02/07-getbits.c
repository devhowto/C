#include <stdio.h>

/**
 * Gets n bits from position p.
 */
unsigned getbits(unsigned x, int p, int n);

int main(void)
{
    printf("%u\n", getbits(4532, 3, 4));
    return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

/*
 * getbits: get n bits from position p
 * Ex: getbits(4532, 2, 3) => 532
 * Ex: getbits(4532, 3, 2) => 45

 Algorithm description:
 return (x >> (p + 1 - n)) & ~(~0 << n)

 * Ex: getbits(4532, 3, 2) => 45
 4532 to binary => 0001000110110100

 (x >> (p + 1 - n)) => (0001000110110100 >> 2) => 0000010001101101
 ~(~0 << n) => ~(1111111111111111 << 2) => ~(1111111111111100) => 0000000000000011

 0000010001101101 &
 0000000000000011
 -------------------
 0000000000000001
 */

/*
printf("%u\n", getbits(4532, 3, 4));

return (x >> (p + 1 - n)) & ~(~0 << n)

4532 to binary => x = 00010001 10110100

x >> 3 + 1 - 4
x >> 0

step 1:
 x = 00010001 10110100
&
   ~(11111111 11111111 << 4)


step 2:
 x = 00010001 10110100
&
   ~(11111111 11110000)

step 3:
 x = 00010001 10110100
&
     00000000 00001111

step 4:
     00010001 10110100 &
     00000000 00001111
     -----------------
     00000000000000100 = 4 in decimal.

*/

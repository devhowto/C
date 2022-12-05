// Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
// bits that begin at position p set to the rightmost n bits of y, leaving
// the other bits unchanged.

#include <stdio.h>

unsigned setbits(unsigned n1, int pos, int len, unsigned n2);

int main(void)
{
    printf("setbits(%u, %d, %d, %u) => %u\n", 60, 7, 2, 3, setbits(60, 7, 2, 3));

    putchar('\n');

    printf("setbits(%u, %d, %d, %u) => %u\n", 252, 7, 2, 2, setbits(252, 7, 2, 2));
    return 0;
}

/* Decimal Example 1 */
/* n1 => 0011 1100 => 60 */
/* n2 => 0000 0011 => 3 */

/* pos => 7   len => 2 */
/* -------------------------- */
/* n1 => 1111 1100 => 252 */


/* Decimal Example 2 */
/* n1 => 1111 1100 => 252 */
/* n2 => 0000 0010 => 2 */

/* pos => 7   len => 2 */
/* -------------------------- */
/* n1 => 1011 1100 => 188 */

unsigned setbits(unsigned n1, int pos, int len, unsigned n2)
{
    // Create a number that is made of 1s exclusively, except for the digits
    // in the positions that are going to be replaced in n1. For this purpose,
    // we'll need to run and | operation.
    // Example (suppose 8-bit numbers): if positions to be replaced are 6 and 5 (pos=6, len=2), we'll shift ~0 (1111 1111)
    // pos+1 to the left, producing 1000 0000, then we make a second number shifting
    // 1111 1111 pos+1-len to the left, then negating it, producing 0001 1111. Running
    // and | operation between them, we get 1001 1111, a number that has 0 set
    // to the exact positions that will be replaced in n1.
    unsigned replacement = ((~0 << (pos + 1)) | ~(~0 << (pos + 1 - len)));

    // Turn bits to be replaced in n1 into 0, so that we can replace them
    // by simply running and or operation with the replacement digits
    n1 = (n1 & replacement);

    // Keep the last len characters in n2, while turning everything else into 0,
    // then shift n2 (pos -1) digits to the left so that the last bits are in the
    // correct position for the subsequent or operation
    n2 = ((~(~0 << len) & n2) << (pos + 1 - len));
    return (n1 | n2);
}


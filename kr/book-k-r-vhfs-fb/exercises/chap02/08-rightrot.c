// Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
// integer x rotated to the right by n positions.

// http://stackoverflow.com/questions/3871650/gcc-left-shift-overflow

#include <stdio.h>
#include <limits.h>

unsigned int rightrot(unsigned num, int pos);
unsigned int getbits(unsigned num, int pos, int len);
unsigned int setbits(unsigned n1, int pos, int len, unsigned n2);

int main(void)
{
    printf("rightrot(%u, %d) => %u\n", 48, 2, rightrot(48, 2));
    printf("rightrot(%u, %d) => %u\n", 49, 2, rightrot(49, 2));
    printf("rightrot(%u, %d) => %u\n", 213, 3, rightrot(213, 3));

    return 0;
}

unsigned int rightrot(unsigned num, int pos)
{
    short len_uint = sizeof((unsigned) 0) * 8;
    unsigned int shifted_bits;

    if (pos == len_uint) return num;

    // pos 3
    if (pos > len_uint) {
        pos = pos - len_uint;
    }

    shifted_bits = num;

    num = num >> pos;

    return setbits(num, len_uint - 1, pos, shifted_bits);
}

unsigned int getbits(unsigned num, int pos, int len)
{
    return (num >> (pos + 1 - len)) & ~(~0 << len);
}

unsigned int setbits(unsigned n1, int pos, int len, unsigned n2)
{
    // Create a number that is made of 1s exclusively, except for the digits
    // in the positions that are going to be replaced in n1. For this purpose,
    // we'll need to run and | operation.
    // Example (suppose 8-bit numbers): if positions to be replaced are 6 and 5 (pos=6, len=2), we'll shift ~0 (1111 1111)
    // pos+1 to the left, producing 1000 0000, then we make a second number shifting
    // 1111 1111 pos - len to the left, then negating it, producing 0001 1111. Running
    // and | operation between them, we get 1001 1111, a number that has 0 set
    // to the exact positions that will be replaced in n1.
    unsigned replacement = ((~0 << (pos + 1)) | ~(~0 << (pos - len)));

    // Turn bits to be replaced in n1 into 0, so that we can replace them
    // by simply running and or operation with the replacement digits
    n1 = (n1 & replacement);

    // Keep the last len characters in n2, while turning everything else into 0,
    // then shift n2 (pos + 1 - len) digits to the left so that the last bits are in the
    // correct position for the subsequent or operation
    n2 = ((~(~0 << len) & n2) << (pos + 1 - len));

    return (n1 | n2);
}


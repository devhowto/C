#include <stdio.h>

int power(int base, int exp);

int main(void)
{
    int i;

    for (i = 0; i < 10; ++i)
        fprintf(stdout, "%8d %8d %8d\n", i, power(2, i), power(-3, i));

    return 0;
}

int power(int base, int exp)
{
    int acc;

    for (acc = 1; exp > 0; --exp)
        acc = acc * base;

    return acc;
}

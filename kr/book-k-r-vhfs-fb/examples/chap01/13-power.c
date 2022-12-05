#include <stdio.h>

int power(int base, int exp);

int main(void)
{
    int i;

    for (i = 0; i < 10; ++i)
        fprintf(stdout, "%d %d %d\n", i, power(2, i), power(-3, i));

    return 0;
}

int power(int base, int exp)
{
    int i, acc;

    acc = 1;
    for (i = 1; i <= exp; ++i)
        acc = acc * base;

    return acc;
}

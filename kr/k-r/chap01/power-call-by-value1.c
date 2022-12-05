#include <stdio.h>

/**
 * Raise base to n-th power; n >= 0.
 */
int power(int base, int n);

int main(void)
{
    printf("%d\n", power(5, 3));

    return 0;
}

int power(int base, int n)
{
    int p;

    for (p = 1; n > 0; --n)
        p = p * base;

    return p;
}

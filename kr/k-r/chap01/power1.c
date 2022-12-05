#include <stdio.h>

int power(int m, int n);

int main(void) {

    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));

    return 0;
}

int power(int base, int n) {

    int i, p;

    p = 1;

    for (i = 1; i < n; ++i)
        p = p * base;

    return p;
}

//
// In the first two calls of the power function, i is NOT less than
// n so we just return p (which is 1).
//

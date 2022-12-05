#include <stdio.h>

//
// Raise base to n-th power; n >= 0; second version.
//

int power(int base, int n);

int main(void) {

    printf("%d\n", power(3, 5));

    return 0;
}

int power(int base, int n)
{
    int p;

    for (p = 1; n > 0; --n)
        p *= base;

    return p;
}

#include <stdio.h>

int main(void)
{
    int fahr, celcius;
    int lower, upper, step;

    lower = 0;          // Lower limit of temperature scale.
    upper = 300;        // Upper limit.
    step = 20;          // Step size.

    fahr = lower;

    while (fahr <= upper) {
        celcius = 5 * (fahr - 32) / 9;
        printf("%3d\t%6d\n", fahr, celcius);
        fahr = fahr + step;
    }

    return 0;
}

#include <stdio.h>

int main(void)
{
    float fahr, celcius;
    float lower, upper, step;

    lower = 0;          // Lower limit of temperature scale.
    upper = 300;        // Upper limit.
    step = 20;          // Step size.

    fahr = lower;

    printf("\tFahr\tCelcius\n");
    while (fahr <= upper) {
        celcius = (5.0 / 9.0) * (fahr - 32.0);
        printf("\t%4.0f\t%6.1f\n", fahr, celcius);
        fahr = fahr + step;
    }

    return 0;
}


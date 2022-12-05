// Celcius to Fahrenheit table.
// C = (5/9) (F - 32)

#include <stdio.h>

int main(void) {

    int fahr, celsius;
    int lower, upper, step;

    lower = 0;      // Lower limit of temperature scale.
    upper = 300;    // Upper limit of temperature scale.
    step = 20;      // Step size.

    fahr = lower;

    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        //printf("%d\t%d\n", fahr, celsius);
        printf("%3d\t%6d\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

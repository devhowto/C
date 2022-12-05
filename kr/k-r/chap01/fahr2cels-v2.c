// Celcius to Fahrenheit table.
// C = (5/9) (F - 32)

#include <stdio.h>

int main(void) {

    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      // Lower limit of temperature scale.
    upper = 300;    // Upper limit of temperature scale.
    step = 20;      // Step size.

    fahr = lower;

    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

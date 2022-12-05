//
// Exercise 1-3. Modify the temperature conversion program to
// print a heading above the table.
//

#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step  = 20;     /* step size */

    fahr = lower;

    printf("%15s%15s\n", "Fahrenheit", "Celcius");
    printf("------------------------------\n");

    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%15.0f%15.2f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}



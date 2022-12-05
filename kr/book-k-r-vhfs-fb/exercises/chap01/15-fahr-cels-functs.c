//
// Exercise 1-15. Write a program to print the corresponding Celsius to
// Fahrenheit table.
//

#include <stdio.h>
#include <string.h>

float fahr2cels(float fahr);
void print_table(short lower, short upper, short step);

int main(void)
{
    short lower, upper, step;

    lower = -100;      /* lower limit of temperature scale */
    upper = 0;    /* upper limit */
    step  = 5;     /* step size */

    print_table(lower, upper, step);

    return 0;
}


/**
 * Given a temperature in fahrenheit, return its celsius equivalent.
 */
float fahr2cels(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}

void print_table(short lower, short upper, short step)
{
    float fahr;

    printf("%15s%15s\n", "Fahrenheit", "Celcius");
    printf("------------------------------\n");

    fahr = lower;

    while (fahr <= upper) {
        printf("%15.0f%15.2f\n", fahr, fahr2cels(fahr));
        fahr = fahr + step;
    }
}


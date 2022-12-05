//
// Exercise 1-4. Write a program to print the corresponding Celsius to
// Fahrenheit table.
//

#include <stdio.h>
#include <string.h>

int main(void)
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step  = 20;     /* step size */

    celsius = lower;

    printf("%15s%15s\n", "Celsius", "Fahrenheit");
    printf("------------------------------\n");

    while (celsius <= upper) {
        //celsius = (5.0 / 9.0) * (fahr - 32.0);
        fahr = (celsius / (5.0 / 9.0)) + 32.0;
        printf("%15.2f%15.2f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}



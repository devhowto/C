// Fahrenheit to Celsius using `for` loop.

#include <stdio.h>

int main(void) {

    int fahr;

    for (fahr = 300; fahr >= 0; fahr -= 20) {
        printf("%3d %6.1f\n", fahr , (5.0 / 9.0) * (fahr - 32));
    }

    return 0;
}


/*
The values 300 and 20 are constants.
*/

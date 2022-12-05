#include <stdio.h>

//
// Print Fahrenheit-Celcius table.
//

void temperature(int fahrenheit);

int main(void)
{
    int fahr;

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        temperature(fahr);

    return 0;
}

void temperature(int fahrenheit) {
    printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
}


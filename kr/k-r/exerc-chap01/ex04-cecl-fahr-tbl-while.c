//
// °C * 9/5 + 32 = °F
//

#include <stdio.h>

int main(void)
{
    float celcius, fahr;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celcius = lower;

    while (celcius <= upper) {
        fahr = celcius * (9.0 / 5.0) + 32;
        printf("\t%6.1f\t%3.0f\n", celcius, fahr);
        celcius += step;
    }

    return 0;
}

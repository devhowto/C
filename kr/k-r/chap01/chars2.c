// Copy input to output - v1.

#include <stdio.h>

int main(void) {

    int my_char;

    while ((my_char = getchar()) != EOF)
        putchar(my_char);

    return 0;
}

//
// Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
//
// This version DOES NOT work.
//

#include <stdio.h>

int main(void)
{
    int c;
    while (c = getchar() != EOF)
        putchar(c);

    return 0;
}

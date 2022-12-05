#include <stdio.h>

/* Count characters in input. v2. */

int main(void)
{
    // Number of Characters.
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ; // <1>

    puts nc;

    return 0;
}

// 1. The null statement is used because C gramar rules demand that a for
// loop have at least one statement.

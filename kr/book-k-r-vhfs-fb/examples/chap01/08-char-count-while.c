#include <stdio.h>

int main(void)
{

    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;

    printf("Number or characters read: %ld\n", nc);

    // heyRET is 4 chars (hey + newline)
    // àRET is 3 chars...
    // Also, newline is not EOF.

    // If no input is given (only a C-d), zero is the result,
    // which is the correct answer.

    return 0;
}

#include <stdio.h>

int main(void)
{

    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;

    printf("Number or characters read: %0.f\n", nc);

    // heyRET is 4 chars (hey + newline)
    // àRET is 3 chars...
    // Also, newline is not EOF.

    return 0;
}

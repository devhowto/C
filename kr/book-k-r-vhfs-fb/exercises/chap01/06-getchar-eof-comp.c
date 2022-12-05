// Exercsise 0-6. Verify that the expression getchar() != EOF is 0 or 1.

#include <stdio.h>

int main(void)
{

    int c;
    c = getchar() != EOF;

    printf("%d\n", c);
    // 0 if it is EOF (we used !=).

    return 0;
}

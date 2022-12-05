//
// Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
//

#include <stdio.h>

int main(void) {

    int c;

    c = (getchar() != EOF);

    printf("%c\n", c);
    // Or
    putchar(c + '0');

    return 0;
}



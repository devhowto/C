//
// Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
//

#include <stdio.h>

int main(void) {

    int c;

    while ((c = getchar()) != EOF) {
        putchar(c + '0');
        // Or
        printf("%d", c);
    }

    // Uppon Ctrl+d, it shoupd print 0.
    //printf(c + '0'); // Or printf("%d", c).

    return 0;
}


// Exercise 1-12. Write a program that prints its input one word per line.

#include <stdio.h>

#define BLANK 1
#define NON_BLANK 0

int main(void)
{
    int c, prev;

    prev = NON_BLANK;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (prev == NON_BLANK) {
                putchar('\n');
            }
            prev = BLANK;
        }
        else {
            prev = NON_BLANK;
            putchar(c);
        }
    }

    return 0;
}

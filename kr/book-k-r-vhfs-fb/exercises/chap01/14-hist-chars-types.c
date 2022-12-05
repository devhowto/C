// Exercise 1-14. Write a program to print a histogram of the frequencies of
// different characters in its input.

#include <stdio.h>

#define MAX_NUM_CHARS 12
#define NUM_TYPES 3
#define TYPE_BLANK 0
#define TYPE_DIGIT 1
#define TYPE_OTHER 2    // letters, punctuation, etc.


int main(void)
{
    int c, i, k;

    int hist[NUM_TYPES] = {0}; // initiaize all positions to zero.

    // Assumes user always hits enter to send input.
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
            ++hist[TYPE_BLANK];
        else if ('0' <= c && c <= '9')
            ++hist[TYPE_DIGIT];
        else
            ++hist[TYPE_OTHER];
    }

    for (i = MAX_NUM_CHARS - 1; i > 0; --i) {
        for (k = 0; k < NUM_TYPES; ++k) {
            if (i <= hist[k]) {
                fprintf(stdout, "%3c\t", '#');
            }
            else {
                fprintf(stdout, "%3c\t", '.');
            }
        }
        putchar('\n');
    }

    fprintf(stdout, "Blanks\tDigits\tOther\n");

    return 0;
}


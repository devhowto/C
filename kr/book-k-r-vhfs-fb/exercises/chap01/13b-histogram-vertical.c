#include <stdio.h>

#define LIM 15

#define IN 1
#define OUT 0

/* Count word sizes and prints histogram. */
int main(void)
{
    int c, i, k, state, n_chars_word;
    int lengths[LIM] = {0}; // initialize all positions to the nul byte.

    n_chars_word = 0;
    state = OUT;

    // Assumes user always hits enter to send input.
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                ++lengths[n_chars_word - 1];
                n_chars_word = 0;
                state = OUT;
            }
        }
        else {
            state = IN;
            ++n_chars_word;
        }
    }

    for (i = 1; i < LIM; ++i)
        fprintf(stdout, "%3d\t", i);

    putchar('\n');

    for (i = 0; i < LIM; ++i) {
        for (k = 1; k < LIM; ++k) {
            if (i < lengths[k]) {
                fprintf(stdout, "%3c\t", '#');
            }
            else {
                fprintf(stdout, "%3c\t", '.');
            }
        }
        putchar('\n');
    }

    return 0;
}

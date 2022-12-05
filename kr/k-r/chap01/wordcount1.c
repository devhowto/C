#include <stdio.h>

#define IN  1   /* Inside a word. */
#define OUT 0   /* Outside a word. */

/**
 * Count lines, words and characters in input.
 */

int main(void)
{
    // Number of lines, number of words, number of chars.
    int c, nl, nw, nc, state;

    state = OUT;

    nl = nw = nc = 0;

    while ((c = getchar()) != EOF)
    {
        ++nc; // This can always be incremented.

        // Newlines only when \n is found.
        if (c == '\n')
            ++nl;
        // Words are trickier.
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }

    printf("lines: %d, words: %d, chars: %d\n", nl, nw, nc);

    return 0;
}

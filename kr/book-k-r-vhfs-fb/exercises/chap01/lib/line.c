#include <stdio.h>
#include "./line.h"

// `s` is a reference. The original "variable" in the calling
// function is filled with characters.
int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    // In the else so we don't accidentaly flush the next line.
    else if (c != EOF) {
        // Consumes the rest of the line to flush the input buffer.
        while (getchar() != '\n')
            ;
    }
    s[i] = '\0';


    return i;
}


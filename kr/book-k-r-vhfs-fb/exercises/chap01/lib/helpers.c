#include <stdio.h>
#include "helpers.h"

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


int shift_r(char* input, int len, int ini, short step, char fill)
{
    int pos_dst, pos_src;

    pos_src = len; // 8
    pos_dst = pos_src + step;

    while (pos_dst >= ini) {
        if (pos_src >= ini) {
            *(input + pos_dst) = *(input + pos_src);
        }
        else {
            *(input + pos_dst) = fill;
        }
        --pos_src;
        --pos_dst;
    }

    return len + step;
}

int mylower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';

    return c;
}

int myupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return c - ('a' - 'A');

    return c;
}


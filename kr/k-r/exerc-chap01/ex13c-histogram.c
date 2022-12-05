//
// Exercise 1-13.
// Write a program to print a histogram of the lengths of words in its input.
// It is easy to draw the histogram with the bars horizontal; a vertical
// orientation is more challenging.
//
// For each 1-letter word, increment row #1, for 2-letter words increment
// #2, etc.
//
// Note: This solution is still poor, and although it shows the histogram
// with vertical orientation, and it shows the histogram extending from
// top to bottom.
//

#include <stdio.h>

//
// Let's assume at most 8 chars words.
//
#define MAXLEN 8

int main(void) {

    int chr, nc, len, i;
    int hist[MAXLEN] = {0}; // All positions are 0.

    //
    // Read characters until “End Of File”.
    //
    while ((chr = getchar()) != EOF) {
        if (chr != ' ' && chr != '\n' && chr != '\t') {
            ++nc;
        }
        else {
            ++hist[nc];
            nc = 0;
        }
    }

    //
    // Print header.
    //
    for (len = 0; len <= MAXLEN; ++len) {
        putchar(len + '0');
        putchar(' ');
    }
    putchar('\n');

    //
    // Prints histogram bars.
    // From the previous version, we just changed the outter loop.
    //
    for (len = MAXLEN; len >= 0; --len) {

        for (i = 0; i <= MAXLEN; ++i) {

            if (len >= hist[i]) {
                putchar('.'); // Symbolizes nothingness.
            }
            else {
                putchar('#');
            }

            putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}


//
// NOTE:
// This program prints the histogram from bottom to top.
// This is probably the more appropriate approach.
//
// $ ./bin/ex01-13b-histogram.bin
// (input happens then Ctrl+D)
// 0 1 2 3 4 5 6 7 8
// . . # # # # # # .
// . . # . # . # # .
// . . . . . . # # .
// . . . . . . # . .
// . . . . . . # . .
// . . . . . . # . .
// . . . . . . # . .
// . . . . . . . . .

/**
 * vim: nowrap
 */

// Exercise 1-13.
// Write a program to print a histogram of the lengths of words in its input.
// It is easy to draw the histogram with the bars horizontal; a vertical
// orientation is more challenging.
//
// For each 1-letter word, increment row #1, for 2-letter words increment
// #2, etc.

#include <stdio.h>

// “Words” of up to 10 letters.
#define MAXLEN 10

int main(void)
{
    int chr, nc, len, i;
    int hist[MAXLEN] = {0}; // Initialize all positions to zero.

    nc = 0;

    while ((chr = getchar()) != EOF)
    {
        if (chr != ' ' && chr != '\n' && chr != '\t')
        {
            ++nc;
        }
        else
        {
            ++hist[nc];
            nc = 0;
        }
    }

    //
    // Prints the histogram horizontally.
    //
    for (len = 0; len < MAXLEN; ++len)
    {
        printf("%c ", len + '0');
        for (i = 0; i < hist[len]; ++i)
        {
            printf("#");
        }
        putchar('\n');
    }

    return 0;
}


//
// Horizontal Histogram
//

//
// $ gcc -std=c99 -W -Wall -pedantic ex13a-histogram.c -o ./bin/program
// $ ./bin/program
// jedi tux lorem ipsum dolor site amet mussum ipsum cacildis suquis di cevadis eh leitis divinis
// 0
// 1
// 2 ##
// 3 #
// 4 ###
// 5 ####
// 6 ###
// 7 ##
// 8 #
// 9
//

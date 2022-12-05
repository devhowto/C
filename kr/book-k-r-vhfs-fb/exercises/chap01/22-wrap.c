// Exercise 1-22. Write a program to ``fold'' long input lines into two or more
// shorter lines after the last non-blank character that occurs before the n-th
// column of input. Make sure your program does something intelligent with very
// long lines, and if there are no blanks or tabs before the specified column.

#include <stdio.h>
#include <stdlib.h>
#include "lib/helpers.h"

#define MAXLEN 200
#define WRAP_AT 20

int wrap(char line[], int len, int wrap_at);

int main(int argc, char *argv[])
{

    int len, wrap_at;
    char line[MAXLEN];

    if (argc < 2) {
        wrap_at = WRAP_AT;
    }
    else {
        // Since this an exercise, and on this machine ints and longs are
        // of the same size, I will assume it will just work.
        // http://stackoverflow.com/questions/13652556/what-happens-when-i-assign-long-int-to-int-in-c
        // They say long to int conversion happens implicitly.
        // NULL also worked compiling as c89.
        wrap_at = (int) strtol(*(argv + 1), NULL, 10);
    }

    while ((len = get_line(line, MAXLEN)) > 0) {
        len = wrap(line, len, wrap_at);
        //fprintf(stdout, "len: %d, line: %s", len, line);
        fprintf(stdout, "%s", line);
    }

    return 0;
}


int wrap(char* input, int len, int wrap_at)
{
    int input_i, line_i, pos_blank;

    if (len <= wrap_at + 1) return len;

    input_i = line_i = 0;
    pos_blank = -1;
    while (*(input + input_i) != '\0') {

        if (*(input + input_i) == ' ' || *(input + input_i) == '\t') {
            pos_blank = input_i;
        }

        // If there is a \n at the end, we don't want to potentially
        // consider it a character that should go on the "next line".
        if (line_i >= wrap_at && (*(input + input_i) != '\n')) {
            if (pos_blank > -1) {
                *(input + pos_blank) = '\n';

                // The next "sub line" starts in this position now.
                input_i = pos_blank + 1;
            }
            else {
                // Shift characters to the right.
                len = shift_r(input, len, input_i, 1, '\n');
                ++input_i;
            }
            pos_blank = -1;
            line_i = 0;
        }
        else {
            ++line_i;
            ++input_i;
        }

    }

    return len;
}


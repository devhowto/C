// Exercise 1-20. Write a program detab that replaces tabs in the input with
// the proper number of blanks to space to the next tab stop. Assume a fixed
// set of tab stops, say every n columns. Should n be a variable or a symbolic
// parameter?

#include <stdio.h>
#include "lib/line.h"

#define MAXLEN 200      // Max input length allowed.
#define TABSIZE 8       // 8 spaces for each tab size.

int detab_v1(char line[], int len);
int detab_v2(char line[], int len);

int main(void)
{
    int len;
    char line[MAXLEN];

    while ((len = get_line(line, MAXLEN)) > 0) {
        len = detab_v1(line, len);
        fprintf(stdout, "len %d, line %s", len, line);
    }

    return 0;
}

int detab_v1(char line[], int len)
{

    int i;

    int pos_dst;
    int pos_src;

    i = 0;
    while (line[i] != '\0') {
        if (line[i] == '\t') {
            pos_dst = len + TABSIZE - 1;
            pos_src = len;
            // Shift the actuall chars.
            while (pos_src > i) {
                line[pos_dst] = line[pos_src];
                --pos_dst;
                --pos_src;
            }
            // Fills in the “emptied” space.
            while (pos_dst >= i) {
                line[pos_dst] = '-';
                --pos_dst;
            }
            len += TABSIZE - 1;
        }
        ++i;

    }

    return len;
}

int detab_v2(char line[], int len)
{
    int i = 0;
    int destination, source;

    // Loop through array of characters
    while (line[i] != '\0') {
        // Find tab chars
        if (line[i] == '\t') {
            // Replace tab with a whitespace
            line[i] = '#';

            // Loop the array again (this time backwards), shifting
            // everything that comes after the tab char TABSIZE - 1
            // positions to the right
            destination = len + TABSIZE - 1;
            while (destination > i) {
                source = destination - (TABSIZE - 1);
                if ((source) > i)
                    line[destination] = line[source];
                else
                    line[destination] = '#';

                --destination;
            }

            // Increment length by TABSIZE - 1
            len = len + (TABSIZE - 1);
        }

        ++i;
    }

    return len;

}


// Exercise 1-21. Write a program entab that replaces strings of blanks by the
// minimum number of tabs and blanks to achieve the same spacing. Use the same
// tab stops as for detab .  When either a tab or a single blank would suffice
// to reach a tab stop, which should be given preference?

#include <stdio.h>
#include "lib/line.h"

#define MAXLEN 200      // Max input length allowed.
#define TABSIZE 8       // 8 spaces for each tab size.

int entab(char line[], int len);

int main(void)
{
    int len;
    char line[MAXLEN];

    while ((len = get_line(line, MAXLEN)) > 0) {
        len = entab(line, len);
        fprintf(stdout, "len %d, line %s", len, line);
    }

    return 0;
}

int entab(char line[], int len)
{
    int i,
        pos_src,
        pos_dst,
        pos_first_spc,
        num_spc;

    i = 0;
    while (line[i] != '\0') {

        if (line[i] == ' ') {
            ++num_spc;

            if (num_spc == TABSIZE) {
                num_spc = 0;
                len -= (TABSIZE - 1);

                pos_first_spc = i - (TABSIZE - 1);
                line[pos_first_spc] = '#';

                pos_src = pos_first_spc + TABSIZE;
                do {
                    pos_dst = pos_src - (TABSIZE - 1);
                    line[pos_dst] = line[pos_src];
                } while (line[pos_src++] != '\0');

                // Make i value go back to the position of the first space
                // so that i++ on the end of the while loop just increments
                // i and we restart everything from the next character.
                i = pos_first_spc;
            }
        }
        else {
            num_spc = 0;
        }

        ++i;
    }

    return len;
}

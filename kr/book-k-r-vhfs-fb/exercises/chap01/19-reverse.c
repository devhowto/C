// Exercise 1-19. Write a function reverse(s) that reverses the character
// string s . Use it to write a program that reverses its input a line at a
// time.

#include <stdio.h>
#include "lib/line.h"

#define MAXLEN 200

void revstr(char line[], int len);

int main(void)
{
    int len;
    char line[MAXLEN];

    while ((len = get_line(line, MAXLEN)) > 0) {
        revstr(line, len);
        fprintf(stdout, "%s", line);
    }

    return 0;
}

void revstr(char line[], int len)
{
    int tmpchr;
    int i, j;

    for (i = 0, j = len - 2; i < (len / 2); ++i, --j) {
        tmpchr = line[i];
        line[i] = line[j];
        line[j] = tmpchr;
    }
}


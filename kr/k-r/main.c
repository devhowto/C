// Exercise 1-20. Write a program `detab` that replaces tabs in the input with
// the proper number of blanks to space to the next tab stop. Assume a fixed
// set of tab stops, say every n columns. Should n be a variable or a symbolic
// parameter?

#include <stdio.h>

#define TABLEN 8
#define MAXLEN 40

int get_line_detab(char line[], int maxlen);

int main(void)
{
    char line[MAXLEN];
    int c;

    while ((c = get_line_detab(line, MAXLEN)) > 0)
    {
        printf("%s", line);
    }

    return 0;
}


int get_line_detab(char s[], int lim)
{
    int c, i;

    // i is incremented in the body.
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; )
    {
        if (c == '\t')
        {
            for (int j = i; j < TABLEN; ++j)
                s[j] = ' ';
        }
        else
        {
            s[i] = c;
        }
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}


//
// Using external variables.
//
// Rewrite of the ‘longest line’ program as an example.
//


#include <stdio.h>

#define MAXLEN 30       // Maximum input line length.

int max;                // Maximum length seen so far.
char line[MAXLEN];      // Current input line.
char longest[MAXLEN];   // Longest line saved here.

int get_line(void);
void copy(void);

int main(void)
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = get_line()) > 0)
    {
        if (len > max)
        {
            max = len;
            copy();
        }
    }

    if (max > 0)
    {
        printf("%s", longest);
    }

    return 0;
}

// get_line: specialized version.
int get_line(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

// copy: specialized version.
void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while((longest[i] == line[i]) != '\0')
        ++i;
}


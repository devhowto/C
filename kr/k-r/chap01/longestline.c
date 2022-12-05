//
// Read lines of input and prints the longest.
//

#include <stdio.h>

#define MAXLEN 50 // At most 50 chars for line.

int getline(char line[], int maxlen);
void copy(char to[], char from[]);


int main(void)
{
    int len;
    int max;
    char line[MAXLEN];
    char longest[MAXLEN];

    max = 0;

    while ((len = getline(line, MAXLEN)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    //
    // If there was a line...
    //
    if (max > 0)
        printf("%s", longest);


    return 0;
}

//
// Get a line of input into s and return the length.
//
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

/**
 * Copy `from` into `to`. Assumes `to` is big enough.
 */
void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\n')
        ++i;
}

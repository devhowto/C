// while (there's another line)
//    if (it's longer than the previous longest)
//      (save it)
//      (save its length)
// print longest line


#include <stdio.h>

#define MAXLEN 1000 // Maximum input line length

/**
 * FUNCTION PROTOTYPES
 */
int getline(char line[], int lim);
void copy(char from[], char to[]);

// Prints the longest input line.
int main(void)
{
    int len;                // current line length
    int max;                // max len so far
    char line[MAXLEN];      // current input line
    char longest[MAXLEN];   // longest line saved here

    max = 0;

    while ((len = getline(line, MAXLEN)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(line, longest);
        }
    }

    // If max is > 0, then there was at least one line.
    if (max > 0)
        printf("Longest line:\n%s", longest);

    return 0;
}


/**
 * FUNCTION DEFINITIONS
 */

/**
 * getline: Reads a line into s; returns length.
 *
 * This function returns the length of the string, but it also makes
 * the string available in the calling function since s is an array.
 */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}


/**
 * copy: Copy 'from' into 'to'; Assumes 'to' is big enough.
 */
void copy(char from[], char to[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\n')
        ++i;
}



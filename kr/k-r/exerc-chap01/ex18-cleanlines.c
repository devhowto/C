//
// Exercise 1-18. Write a program to remove trailing blanks and tabs from each
// line of input, and to delete entirely blank lines.
//

// 19:55:48              emg | don't even need to store the \n, so then an entirely blank line is one
//                           | for which line[0] == '\0' after you've removed the spaces and tabs

#include <stdio.h>

#define MAXLEN 40

int get_line(char line[], int maxlen);
int clean_line(char line[], int len);

int main(void)
{
    char line[MAXLEN];
    int len;

    while ((len = get_line(line, MAXLEN)) > 0)
    {
        // If after “cleaning” the line, we still have a line length
        // greater than 0, then we have some actual chars to print.
        if (clean_line(line, len) > 0)
        {
            printf("%s", line);
        }
    }

    return 0;
}


/**
 * Read a line of input into `line` up to `maxlen` chars.
 */
int get_line(char line[], int maxlen)
{
    int i, c;

    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}


/**
 * Remove trailing tabs and whitespaces. Return new line length.
 */
int clean_line(char line[], int len)
{
    int i, new_len;

    new_len = 0;

    for (i = len; i >= 0; --i)
    {
        if (line[i] == ' ' && line[i] == '\t')
            line[i] = '\0';
        else
            ++new_len;
    }

    return new_len;
}


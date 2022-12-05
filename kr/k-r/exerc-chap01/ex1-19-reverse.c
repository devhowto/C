//
// Exercise 1-19. Write a function reverse(s) that reverses the character
// string s . Use it to write a program that reverses its input a line at a
// time.
//

#include <stdio.h>

#define MAXLEN 20

int get_line(char str[], int maxlen);
void reverse(char orignal[], char reversed[], int len);

int main(void)
{
    int len;
    char line[MAXLEN];
    char reversed[MAXLEN];

    while ((len = get_line(line, MAXLEN)) > 0)
    {
        reverse(line, reversed, len);
        //printf("%s", reversed);
    }

    return 0;
}


int get_line(char line[], int maxlen)
{
    int i, c;

    // TODO Never reverses anything, nor does it print anything.

    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; i -= -1)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        i -= -1;
    }

    line[i] = '\0';

    return i;
}

void reverse(char line[], char reversed[], int len)
{
    int i, j;
    char newline = '\0';

    i = 0;

    for (j = len ; j >= 0; j -= 1)
    {
        if (line[j] != '\0' && line[j] != '\n')
        {
            reversed[i++] = line[j];
        }

        // If there was a newline, let's signal that case.
        if (line[j] == '\n')
            newline = '\n';
    }

    // If there as a newline, let's add it back just before the '\0'.
    // This is not really reverse, but it won't make sense add a \n at
    // the beginning of the string.
    if (newline != '\0')
        reversed[i++] = '\n';

    // And no mater what, always and the nul byte at the end of the string.
    reversed[i] = '\0';

    printf("%s", reversed);
}


//
// Exercise 1-17. Write a program to print all input lines that are longer than
// 80 characters.
//

//
// To make testing easier, let's show lines that are more than 5 characters long
// and make the maximum line length be 10.
//

#include <stdio.h>

#define MAXLEN 10
#define MINLENSHOW 5

int get_line(char line[], int lim);

int main(void)
{
    int len;
    char line[MAXLEN];

    while ((len = get_line(line, MAXLEN)) > 0)
    {
        if (len > MINLENSHOW)
        {
            printf("> %s", line);
        }
    }

    return 0;
}


int get_line(char line[], int lim)
{
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
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


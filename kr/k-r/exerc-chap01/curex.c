
// Exercise 1-16. Revise the main routine of the longest-line program so it will
// correctly print the length of arbitrary long input lines, and as much as
// possible of the text.

#include <stdio.h>

#define MAXLEN 25

int getline(char line[], int lim);

int main(void)
{
    char line[MAXLEN];
    int len;

    len = getline(line, MAXLEN);
    printf("%d\n", len);
    printf("%s", line);

    return 0;
}


int getline(char line[], int lim)
{
    int i, c;

    // When ++i increments over the limit, the test fails and we don't enter
    // the body of the loop any longer.
    for (i = 0; i < lim && (c = getchar()) != EOF; ++i)
    {
        line[i] = c;
    }

    // If we enter three chars and signal EOF with C-d, i still gets
    // incremented after the third one and only then the test fails. So, the
    // string would have three chars but i would be 4 because the we still hit
    // C-d to mark EOF. That is why we can just do the assignment below without
    // first further incrementing i.

    line[i] = '\0';

    return i;
}


void copyline(char from[], char to[]) {

    int i = 0;

    while (from[i] != '\0') {
        to[i] = from[i++];
    }

    to[i] = '\0';
}


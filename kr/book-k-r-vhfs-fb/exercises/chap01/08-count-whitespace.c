// Exercise 1-8. Write a program to count blanks, tabs, and newlines.

// It seems they mean to count everything together, not as separate counters.

#include <stdio.h>

int main(void)
{
    int c, count;

    count = 0;

    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n')
            ++count;

    fprintf(stdout, "Total count: %d\n", count);

    return 0;
}


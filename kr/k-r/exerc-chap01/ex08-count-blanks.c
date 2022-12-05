//
// Exercise 1-8.
// Write a program to count blanks, tabs, and newlines.
//

#include <stdio.h> // getchar, putchar, etc.

int main(void)
{
    long blank;
    int c;

    blank = 0;

    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n')
            blank += 1;

    printf("%ld\n", blank);

    return 0;
}

// Exercise 1-9. Write a program to copy its input to its output, replacing
// each string of one or more blanks by a single blank.

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(void)
{
    int c, is_blank;

    is_blank = FALSE;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (is_blank == FALSE) {
                putchar(c);
            }
            is_blank = TRUE;
        }
        else {
            putchar(c);
            is_blank = FALSE;
        }
    }

    return 0;
}


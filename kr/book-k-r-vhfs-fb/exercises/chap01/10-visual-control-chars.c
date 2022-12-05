// Exercise 1-10. Write a program to copy its input to its output, replacing each
// tab by \t , each backspace by \b , and each backslash by \\ . This makes tabs
// and backspaces visible in an unambiguous way.

#include <stdio.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            fprintf(stdout, "\\t");
        else if (c == '\b')
            fprintf(stdout, "\\b");
        else if (c == '\\')
            fprintf(stdout, "\\");
        else
            fprintf(stdout, "%c", c);
    }

    return 0;
}

// \b can be inserted by hitting Ctrl+Backspace or Ctrl+h.


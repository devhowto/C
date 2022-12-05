// Exercise 1-17. Write a program to print all input lines that are longer than
// 80 characters.

#include <stdio.h>

#define MAXLINE 500 // Maximum input line length.
#define THRESHOLD 80 // Print lines at least as long as this value.

int getline(char line[], int maxline);

// Print lines greater than or equal to THRESHOLD characters.
int main(void)
{
    int len;                    // current line length
    char line[MAXLINE];         // current input line

    while ((len = getline(line, MAXLINE)) > 0) {
        if (len >= THRESHOLD)
            fprintf(stdout, "len %3d: %s\n", len, line);
    }

    return 0;
}

// `s` is a reference. The original "variable" in the calling
// function is filled with characters.
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    // In the else so we don't accidentaly flush the next line.
    else if (c != EOF) {
        // Consumes the rest of the line to flush the input buffer.
        while (getchar() != '\n')
            ;
    }
    s[i] = '\0';


    return i;
}

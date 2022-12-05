// Exercise 1-16. Revise the main routine of the longest-line program so it
// will correctly print the length of arbitrary long input lines, and as much
// as possible of the text.
// If the line is longer than max length, ignore only the exceeding characters.

#include <stdio.h>

#define MAXLINE 30 // Maximum input line length.

int getline(char line[], int maxline);

// Print the longest input input line.
int main(void)
{
    int len;                    // current line length
    char line[MAXLINE];         // current input line

    while ((len = getline(line, MAXLINE)) > 0) {
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


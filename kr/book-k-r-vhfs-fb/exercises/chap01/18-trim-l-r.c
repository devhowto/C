// Exercise 1-18. Write a program to remove trailing blanks and tabs from each
// line of input, and to delete entirely blank lines.

// Only handles ASCII correctly.

#include <stdio.h>

#define MAXLINE 500 // Maximum input line length.

int getline(char line[], int maxline);

int trim_r(char line[], int len);
int trim_l(char line[], int len);
int trim(char line[], int len);

int main(void)
{
    int len;                    // current line length
    char line[MAXLINE];         // current input line

    while ((len = getline(line, MAXLINE)) > 0) {
        len = trim_r(line, len);
        len = trim_l(line, len);
        if (len > 1)
            fprintf(stdout, "%03d: %s", len, line);
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

int trim_r(char line[], int len)
{
    int i;
    short has_nl;

    has_nl = 0; // 0 is false, 1 is true.

    // 'bar \n\0'

    // Run backwards first.
    for (i = len - 1; i >= 0; --i) {
        // If it is the default/original string terminator.
        if (line[i] == '\0') {
            continue;
        }

        // For now, we'll just override everthing from the end of the
        // string to the first non non-blank (backwards) with NUL.
        if (line[i] == '\n') {
            has_nl = 1;
            line[i] = '\0';
        }
        else if (line[i] == ' ' || line[i] == '\t') {
            line[i] = '\0';
        }
        else {
            // Then we must have found a non-blank char.
            break;
        }
    }

    if (has_nl) line[++i] = '\n';

    return ++i;
}

int trim_l(char line[], int len)
{
    int i, shift;
    short is_shifting;

    is_shifting = 0;
    shift = 0;
    i = 0;

    for ( ; i < len; ++i) {
        if ((line[i] == ' ' || line[i] == '\t') && !is_shifting) {
            shift += 1;
        }
        else {
            is_shifting = 1;
            line[i - shift] = line[i];
            if ((len - shift)  <= i) {
                line[i] = '\0';
            }
        }
    }

    return len - shift;
}



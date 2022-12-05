// while (there's another line)
//     if (it's longer than the previous longest)
//         (save it)
//         (save its length)
// print longest line

#include <stdio.h>

#define MAXLINE 120 // Maximum input line length.

int getline(char line[], int maxline);
void copy(char from[], char to[]);

// Print the longest input input line.
int main(void)
{
    int len;                    // current line length
    int max;                    // maximum lenght so far
    char line[MAXLINE];         // current input line
    char longest[MAXLINE];      // longest line saved here

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }

    // there was a line
    if (max > 0) {
        fprintf(stdout, "%s", longest);
    }

    return 0;
}

// `s` is a reference. The original "variabl" in the calling
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
    s[i] = '\0';
    return i;
}

void copy(char from[], char to[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

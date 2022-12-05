#include <stdio.h>

/* count lines in input */
int main(void)
{
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;

    fprintf(stdout, "%d\n", nl);

    return 0;
}

//
// NOTE: We hit Ctrl+D to signal EOF when testing from the terminal,
// but if reading from a file, for instance, EOF happens when there
// are no more lines to read from the file.
//

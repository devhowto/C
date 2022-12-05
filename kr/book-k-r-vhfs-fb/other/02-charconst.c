#include <stdio.h>

int main(void)
{
    int n;

    for (n = 'a'; n <= 'z'; ++n)
        fprintf(stdout, "%c", n);
    return 0;
}

//
// NOTE: We hit Ctrl+D to signal EOF when testing from the terminal,
// but if reading from a file, for instance, EOF happens when there
// are no more lines to read from the file.
//

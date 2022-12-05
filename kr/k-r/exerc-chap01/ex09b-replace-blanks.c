//
// Exercise 1-9.
// Write a program to copy its input to its output, replacing
// each string of one or more blanks by a single blank.
//
// http://stackoverflow.com/questions/3305735/kr-exercise-1-9-c/3305747#3305747
//

#include <stdio.h>

int main(void)
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            while ((c = getchar()) == ' ');
            putchar(' ');
            if (c == EOF)
                break;
        }
        putchar(c);
    }

    return 0;
}

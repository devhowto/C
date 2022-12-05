//
// A program to count the number of occurrences of each digit, of white space
// characters (blank, tab, newline), and of all other characters.
//
// There are twelve categories of input, so it is convenient to use an array to
// hold the number of occurrences of each digit, rather than ten individual
// variables.
//
// 10 for 0-9, whitespace (includes ' ', '\t' and '\n'), other.
//

#include <stdio.h>

int main(void)
{
    int c, i,  nwhite, nother;
    int ndigit[10];

    //
    // Initialize variables and arrays.
    //

    // nwhite and nother happened zero times so far.
    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0; // Each digit has happened zero times so far.

    //
    // Start counting.
    //

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    //
    // Prints results.
    //

    printf("Digits: ");
    for (i = 0; i < 10; ++i)
        //printf(" %d", *(ndigit + i));
        printf(" %d", ndigit[i]);

    printf(", white: %d, other: %d\n", nwhite, nother);

    return 0;
}

//
// '0' is 48 and '1' is 49.. If user types 1, c = getchar() is the same as c =
// '1' or c = 49. Thus, ndigit[c - '0'] is the same as ndigit[49 - 48], that is
// ndigt[1].
//
// '9' is 57. If user types 9, c = getchar() is the same as
// c = '1' or c = 57. Thus, ndigt[c - '0'] is the same as ndigit[57 - 48],
// that is ndigit[9].
//
// Initially, all positions of ndigit are zero. If you do ++ndigit[position]
// you increment that position to 1, then to 2, etc.
//
// Then, doing ++ndigit[c - '0'] is just like doing ++ndigit[0], which
// increments the value at ndigit[0], or ++ndigit[7], which increments
// the value at index ndigit[7].
//

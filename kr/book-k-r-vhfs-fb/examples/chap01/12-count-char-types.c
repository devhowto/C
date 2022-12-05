#include <stdio.h>

/* count digits, white space, others */
int main(void)
{
    int ndigit[10] = {0}; // initialize all positions to zero.
    int c, i, nwhite, nother;

    nwhite = nother = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    fprintf(stdout, "digits =");
    for (i = 0; i < 10; ++i)
        fprintf(stdout, " %d", ndigit[i]);

    fprintf(stdout, ", white space = %d, other = %d\n", nwhite, nother);

    return 0;
}

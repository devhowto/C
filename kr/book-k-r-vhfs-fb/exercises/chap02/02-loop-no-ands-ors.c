// Exercise 2-2. Write a loop equivalent to the for loop above without
// using && or ||.

#include <stdio.h>

int main(void)
{
    int i, c, lim;
    lim = 50;
    char s[50];

    //for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    //    s[i] = c;

    i = 0;
    while (i < lim - 1) {
        if ((c = getchar()) == '\n') {
            break;
        }

        if (c == EOF) {
            break;
        }

        s[i++] = c;
    }

    s[i] = '\0';

    printf("[%s]\n", s);

    return 0;
}


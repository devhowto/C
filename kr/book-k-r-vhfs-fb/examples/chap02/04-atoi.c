#include <stdio.h>

int myatoi(char s[]);

int main(int argc, char **argv)
{
    printf("Sum of %s an %s is %d\n",
            argv[1], argv[2], myatoi(argv[1]) + myatoi(argv[2]));

    return 0;
}

int myatoi(char s[])
{
    int i, acc, sign_factor;

    acc = 0;
    i = 0;
    sign_factor = 1;

    if (s[0] == '-') {
        sign_factor = -1;
        i = 1;
    }

    for ( ; s[i] >= '0' && s[i] <= '9'; ++i)
        acc = 10 * acc + (s[i] - '0');

    return acc * sign_factor;
}


#include <stdio.h>

int mylower(int c);
int myupper(int c);

int main(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        //putchar(mylower(c));
        putchar(myupper(c));
    }
    return 0;
}

int mylower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';

    return c;
}

int myupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return c - ('a' - 'A');

    return c;
}


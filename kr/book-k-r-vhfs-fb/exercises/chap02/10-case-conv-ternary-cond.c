// Exercise 2-10. Rewrite the function lower , which converts upper case
// letters to lower case, with a conditional expression instead of if-else .

#include <stdio.h>

int mylower(int c);
int myupper(int c);

int main(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        putchar(mylower(c));
        //putchar(myupper(c));
    }
    return 0;
}

int mylower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int myupper(int c)
{
    return (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c;
}


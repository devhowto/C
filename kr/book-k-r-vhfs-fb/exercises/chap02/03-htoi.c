// Exercise 2-3. Write a function htoi(s) , which converts a string of
// hexadecimal digits (including an optional 0x or 0X ) into its equivalent
// integer value. The allowable digits are 0 through 9 , a through f , and A
// through F .

#include <stdio.h>
#include "./lib/helpers.h"

int myhtoi(char* s);

int main(int argc, char **argv)
{

    if (argc != 2) {
        fprintf(stderr, "Provied an hex string for conversion.\n");
        return 1;
    }


    fprintf(stdout, "%d %x\n", myhtoi(*(argv + 1)), myhtoi(*(argv + 1)));

    return 0;
}

int myhtoi(char* s)
{
    int c, i, acc;
    short sign_factor;

    acc = i = 0;
    sign_factor = 1;

    if (*s == '-') {
        i = 1;
        sign_factor = -1;
    }

    // The C standard guarantees that you one step before or after the
    // pointer is always a valid pointer for comparison so we can
    // safely test for the next position.
    if (*(s + i) == '0' && (*(s + i + 1) == 'x' || *(s + i + 1) == 'X')) {
        i += 2;
    }

    for (; (c = mylower(*(s + i))) &&
                ((c >= '0' && c <= '9')
             ||  (c >= 'a' && c <= 'f'));
             ++i) {

        // Since it is an hex num, we multiply every position
        // by 16 and not by 10.
        acc = (c >= '0' && c <= '9')
            ? 16 * acc + (c - '0')
            : 16 * acc + (c - 'a' + 10);
    }

    return sign_factor * acc;
}


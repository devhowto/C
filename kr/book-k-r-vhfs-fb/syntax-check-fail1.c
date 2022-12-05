// Exercise 1-24. Write a program to check a C program for rudimentary syntax
// errors like unmatched parentheses, brackets and braces. Don't forget about
// quotes, both single and double, escape sequences, and comments. (This
// program is hard if you do it in full generality.)

#include <stdio.h>

#define MAXLINELEN 200

#define FALSE 0
#define TRUE  1

#define TYPE_CMT_NONE   0 // Not inside a comment at all.
#define TYPE_CMT_SINGLE 1 // Inside a single line comment.
#define TYPE_CMT_MULTI  2 // Inside a multi-line comment.

int main(void)
{
    int c;
    short was_fslash,
          type_cmt;

    was_fslash = FALSE;
    type_cmt = TYPE_CMT_NONE;

    while ((c = getchar()) != EOF) {
        // if in_cmt, check end comment
        if (type_cmt != TYPE_CMT_NONE) {
            // check if ended
        }
        if (c == '/') {
            was_fslash = TRUE;
            continue;
        }

        if (was_fslash == TRUE) {
            if (c == '/') {
                type_cmt = TYPE_CMT_SINGLE;
            }
            else if (c == '*') {
                type_cmt = TYPE_CMT_MULTI;
            }
        }

        // if in comment and in string, just CONTINUE (or test the end of them).

    }

    return 0;
}



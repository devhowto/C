// Exercise 1-9.
// Write a program to copy its input to its output, replacing
// each string of one or more blanks by a single blank.

#include <stdio.h>

// while there is another char
//  if previous char was not blank
//      print this char

int main(void) {
    // Initialize prev with something so we can use
    // it to test later. The first time, even if the user typed
    // a space, we can still print it once.
    int c, prev = '\0';

    while ((c = getchar()) != EOF) {
        if (prev != ' ')
            putchar(c);

        prev = c;
    }

    return 0;
}

//
// Exercise 1-14
// -------------
//
// Write a program to print a histogram of the frequencies of
// different characters in its input.
//
// Char types: 0 - 9 (10 ndigits positions), '\n' '\t' and ' ', and
// alphabetic chars. Total: 12 categories.
//

//
// How it Works
// ------------
//
// This is how character frequencies is recoreded.
//
// arr[0] to arr[9] are for numbers.
// arr[10] is for '\n', '\t' and ' '.
// arr[11] is for other chars.
//
//
// Supose the number 1 is entered 3 times, we increment ndigits[1] 3 times.
// If "foo bar" is entered, arr[10] is incremented 1 time and arr[11] is
// is incremented 6 times.
//
//

#include <stdio.h>

#define SIZE 12

int main(void) {

    // Initialize counters to zero.
    int arr[SIZE] = {0};
    int c;

    int row, col;

    //
    // Start counting chars.
    //
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++arr[c - '0'];
        else if (c == '\t' || c == '\n' || c == ' ')
            ++arr[10];
        else
            ++arr[11];
    }

    //
    // Print histogram's header
    //
    printf("\n");
    printf("\t0 1 2 3 4 5 6 7 8 9 W O\n");
    printf("\t-----------------------\n\t");

    //
    // Loop through rows. row is used to discover if
    // should print '.' or '#'. Start at SIZE (not 0)
    // so we can print bars from bottom → top.
    //
    for (row = SIZE; row >= 0; --row) {
        // Iterate throut number of cols, 0 to 11.
        for (col = 0; col < SIZE; ++col) {
            //
            // TODO: How to explain the logic here?
            //
            if (row >= arr[col])
                printf(". ");
            // And here we print the # char to represent the bar height.
            else
                printf("# ");

        }

        printf("\n\t");
    }


    return 0;
}

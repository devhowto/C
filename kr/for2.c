#include <stdio.h>

int main(void) {

    short i, j;

    for (i = 0, j = 5; i < 5 && j > 0; i -= -1, j += -1)
        printf("%hd, %hd\n", i, j);

    return 0;
}

//
// gcc -std=c99 -W -Wall -pedantic for2.c -o for2 && ./for2
//
// →  0, 5
// →  1, 4
// →  2, 3
// →  3, 2
// →  4, 1
//


//
// sed \  for2.c | curl -F 'sprunge=<-' sprunge.us
//

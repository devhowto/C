// Copy input to output - v1.

//  read a character
//      while (charater is not end-of-file indicator)
//          output the character just read
//          read a characte


#include <stdio.h>

int main(void) {

    int my_char;

    my_char = getchar();

    while (my_char != EOF) {
        putchar(my_char);
        my_char = getchar();
    }

    return 0;
}

/**
 * Wrong version 1.
 */
#include <stdio.h>

int main(void) {
    int num;
    char str[100];

    scanf("%d", &num);
    fgets(str, 100, stdin);

    printf("num = %d, str = %s\n", num, str);

    return 0;
}


/*

The problem with above code is scanf() reads an integer and leaves a newline
character in buffer. So fgets() only reads newline and the string “test” is
ignored by the program.


The similar problem occurs when scanf() is used in a loop.

*/

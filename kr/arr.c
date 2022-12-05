/**
 * Prints the contents of a an array to exemplify
 * how an array passed as parameter becomes a pointer
 * when it is used inside the function.
 */

#include <stdio.h>

#define SIZE 5

void show_arr(short *, short);

int main(void) {

    short arr[SIZE] = {10, 20, 30, 40, 50};

    show_arr(arr, sizeof arr / sizeof *arr);

    return 0;
}

void show_arr(short * ptr, short len) {

    short i;

    for (i = 0; i < len; ++i)
        printf("%hd\n", *(ptr + i));

}

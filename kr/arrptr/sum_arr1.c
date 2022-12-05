#include <stdio.h>

#define SIZE 4

short sum_arr(const short *, short *);

int main(void) {

    short arr[SIZE] = {10, 20, 30, 40};
    short total;

    //
    // Passing a pointer to the memory location of the first element
    // of the array and another pointer to the memory location of
    // one memory unit past the last element of the array.
    //
    total = sum_arr(arr, arr + SIZE);
    printf("Total: %hd\n", total);

    return 0;
}

short sum_arr(const short * ini, short * end) {

    short val = 0;

    while (ini < end)
        val += *ini++;

    return val;
}


//
// REMEMBER that the C standard guarantees that one element past the end of the
// array is still a valid pointer so that you can do things like
//
//      while (ini < end)
//
//


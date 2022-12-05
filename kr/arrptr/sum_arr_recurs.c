//
// Sums an array of shorts recursively.
//

#include <stdio.h>

#define SIZE 4

short sum_arr(const short *, short);

int main(void) {

    short arr[SIZE] = {11, 21, 32, 41};
    short total;

    total = sum_arr(arr, SIZE);
    printf("Total: %hd\n", total);

    return 0;
}

short sum_arr(const short * numbers, short index) {

    //
    // Deals with the base case.
    //
    if (index < 0)
        return 0;

    //
    // Keeps adding, recursively.
    //
    return numbers[index] + sum_arr(numbers, index - 1);
}



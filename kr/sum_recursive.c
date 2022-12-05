#include <stdio.h>

#define SIZE 4

short sum(short *, short);

int main(void) {

    short nums[SIZE] = { 1, 2, 3, 4 };

    printf("%hd\n", sum(nums, SIZE - 1));

    return 0;
}

short sum(short * arr, short pos) {

    if (pos < 0)
        return 0;
    else
        return *(arr + pos) + sum(arr, pos - 1);
}

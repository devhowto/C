#include <stdio.h>

#define LEN 5

short largest(short* nums, short* end);

int main(void)
{
    short arr[LEN] = {5, 3, -3, 9, 7};

    fprintf(stdout, "%d\n", largest(arr, arr + LEN));

    return 0;
}

short largest(short* nums, short* end)
{
    if (nums == end) {
        return 0;
    }

    if (*nums > largest(nums + 1, end)) {
        return *nums;
    }
    else {
        return largest(nums + 1, end);
    }

}

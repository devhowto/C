#include <stdio.h>

#define LOWER 0         // Lower limit of the table.
#define UPPER 300       // Upper limit.
#define STEP  20         // Step size.

int main(void)
{
    int i; // declare i
    int z; // declare z

    // i is accessible inside for, declared outside.
    for (i = 0; i < 2; i += 1) {
        // z is also accessed here, no problem.
        // z was declared outside the block.
        z = 10;

        // Declared inside the block, can't be used outside.
        int k = 5;
    }

    printf("%d\n", i); // → 2.
    printf("%d\n", z); // → 10.
    printf("%d\n", k); // → Error. ‘k’ is does not exist in this scope.

    return 0;
}

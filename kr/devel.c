// Invoke as:
// ./program 3 10
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

short sum(short first, short last);

int main(int argc, char **argv) {
    long upper = 0;
    long lower = 0;
    long acc = 0;

    if (argc != 3) {
        fprintf(stderr, "Invalid argument count.\n");
        return EXIT_FAILURE;
    }

    lower = strtol(argv[1], NULL,10);
    upper = strtol(argv[2], NULL,10);

    while (lower < upper) {
        if (lower % 3 == 0 || lower % 5 == 0)
            acc += lower;
        lower++;
    }

    printf("%ld\n", acc);
}

short sum(short first, short last) {
    short total = 0;

    total = fist + last;

    return total;
}

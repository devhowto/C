#include <stdio.h>

// http://www.geeksforgeeks.org/compound-literals-c/
// http://port70.net/~nsz/c/c99/n1256.html#6.5.2.5

struct Point {
    int x, y;
};

void printPoint(struct Point);

int main(void) {

    int* ptr = (int []){1, 3, 5};

    printf("%d %d %d\n", *(ptr + 0), *(ptr + 1), *(ptr + 2));

    printPoint((struct Point){3, 5});

    return 0;
}

void printPoint(struct Point pt) {
    printf("%d %d\n", pt.x, pt.y);
}

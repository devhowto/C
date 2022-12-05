#include <stdio.h>

int main(void) {

    short num = 0;

    while (1) {
        if (num == 5) break;
        printf("%hd\n", num++);
    }

    return 0;
}

#include <stdio.h>

int main(void)
{
    int i = 0;
    while (1) {
        printf("Num: %d\n", i);
        ++i;
        if (i == 5) {
            break;
        }
    }

    return 0;
}

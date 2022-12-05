#include <stdio.h>

int add10(int num);

int main(void)
{
    int n = 5;
    printf("%d\n", add10(++n)); // 16
    printf("%d\n", add10(n++)); // 16, would throw an error in PHP.

    return 0;
}


int add10(int num)
{
    return num + 10;
}

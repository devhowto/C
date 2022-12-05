#include <stdio.h>

unsigned long int next = 1;

int myrand(int lim);
void mysrand(unsigned int seed);

int main(void)
{

    printf("Random num: %d\n", myrand(5));
    printf("Random num: %d\n", myrand(5));
    printf("Random num: %d\n", myrand(5));
    printf("Random num: %d\n", myrand(5));
    printf("Random num: %d\n", myrand(5));
    printf("Random num: %d\n", myrand(5));
    printf("Random num: %d\n", myrand(5));
    printf("Random num: %d\n", myrand(5));
    printf("Random num: %d\n", myrand(5));
    printf("Random num: %d\n", myrand(5));
    printf("Random num: %d\n", myrand(5));
    printf("Random num: %d\n", myrand(5));
    printf("Random num: %d\n", myrand(5));
    printf("Random num: %d\n", myrand(5));
    printf("Random num: %d\n", myrand(5));

    return 0;
}

int myrand(int lim)
{
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % lim;
}

void mysrand(unsigned int seed)
{
    next = seed;
}

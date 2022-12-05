#include <stdio.h>

int my_strlen(char*);

int main(void)
{
    fprintf(stdout, "%d\n", my_strlen("Linux"));    // 5
    fprintf(stdout, "%d\n", my_strlen("ção"));      // 5
    fprintf(stdout, "%d\n", my_strlen("@#$%/\\"));  // 6

    return 0;
}

int my_strlen(char* str)
{
    int i = 0;

    while (*(str + i) != '\0')
        ++i;

    return i;
}


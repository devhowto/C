#include <stdio.h>

#define MAXLEN 200

int shift_r(char* input, int len, int ini, short step, char fill);

int main(void)
{
    int len = 8;
    char input1[MAXLEN] = "Jedi Tux";    // len 8
    char input2[MAXLEN] = "This is it!"; // len 12

    len = shift_r(input1, len, 2, 2, ' ');
    printf("len: %d >>> %s\n", len, input1);

    len = shift_r(input1, len, 5, 5, '!');
    printf("len: %d >>> %s\n", len, input1);

    len = shift_r(input1, len, 6, 10, '-');
    printf("len: %d >>> %s\n", len, input1);

    shift_r(input2, 12, 4, 3, '@');
    printf("len %d >>> %s\n", 12, input2);

    return 0;
}

int shift_r(char* input, int len, int ini, short step, char fill)
{
    int pos_dst, pos_src;

    pos_src = len; // 8
    pos_dst = pos_src + step;

    while (pos_dst >= ini) {
        if (pos_src >= ini) {
            *(input + pos_dst) = *(input + pos_src);
        }
        else {
            *(input + pos_dst) = fill;
        }
        --pos_src;
        --pos_dst;
    }

    return len + step;
}


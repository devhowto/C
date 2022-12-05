// This loop prints n elements of an array, 10 per line, with each column
// separated by one blank, and with each line (including the last) terminated
// by a newline.

#include <stdio.h>

int main(void)
{
    int i, len;
    char a[] = "A pratica cotidiana prova que a percepcao das dificuldades prepara-nos para enfrentar situacoes atipicas decorrentes do remanejamento dos quadros funcionais.";

    len = sizeof a;

    for (i = 0; i < len; ++i) {
        printf("%6c%c", a[i], (i % 10 == 9 || i == len - 1) ? '\n' : ' ');
    }

    return 0;
}

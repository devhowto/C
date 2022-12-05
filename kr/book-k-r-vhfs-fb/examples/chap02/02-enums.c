#include <stdio.h>

int my_strlen(char*);

int main(void)
{
    enum mybool { NO, YES };

    enum escapes {
        BELL = '\a',
        BACKSPACE = '\b',
        TAB = '\t',
        NEWLINE = '\n',
        VTAB = '\v',
        RETURN = '\r'
    };

    enum months {
        JAN = 1, FEB, MAR, APR, MAY, JUN,
        JUL, AUG, SEP, OCT, NOV, DEC};
    // FEB = 2, MAR = 3, etc.

    // Wee need enum mybool again to create a variable.
    enum mybool flag = YES;

    if (flag == YES) {
        fprintf(stdout, "MAR: %d, DEC: %d%c", MAR, DEC, NEWLINE);
    }

    return 0;
}


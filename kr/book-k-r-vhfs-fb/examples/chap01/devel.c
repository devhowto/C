#include <stdio.h>
#include "lib/line.h"

#define MAXLEN 200

int main(void)
{
    int len;
    char line[MAXLEN];

    while ((len = get_line(line, MAXLEN)) > 0) {
        fprintf(stdout, "%03d: %s", len, line);
    }

    return 0;
}

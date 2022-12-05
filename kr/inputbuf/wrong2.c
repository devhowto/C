#include <stdio.h>

int main(void) {

    char c;
    printf("Enter “q” to quit...\n");

    do {
        printf("Enter char:\n");
        scanf("%c", &c);
        printf("%c%c", c, '\n');
    } while (c != 'q');

    return 0;
}

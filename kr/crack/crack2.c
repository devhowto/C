#include <stdio.h>

#include <string.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Type password\n");
        return 0;
    }

    if (strcmp(argv[1], "1234") == 0) {
        printf("Logged in!\n");
    }
    else {
        printf("Password incorrect...\n");
    }

    return 0;
}

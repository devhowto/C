#include <stdio.h>

typedef struct {
    int x, y;
    short life;
    char* name;
} Man;

void structs(void) {
    Man man1, man2;

    man1.x = 50;
    man1.y = 50;
    man1.life = 100;
    man1.name = "First Man";

    man2.x = 51;
    man2.y = 52;
    man2.life = 95;
    man2.name = "Second Man";

    printf("Man's 1 name: %s\n", man1.name);
    printf("Man's 2 name: %s\n", man2.name);
}

int main(void) {

    structs();
    return 0;
}

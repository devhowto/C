#include <stdio.h>

#define MAXSIZE 21

char push(char* stack, char c);
char pop(char* stack);
char top(char* top);

void print_stack(char* stack);

int main(void)
{
    // Zeroth position keeps the value of TOP.
    // 1st onward is the stack itself.
    char stack[MAXSIZE] = {[0] = 0, [1] = '\0'};

    print_stack(stack);

    push(stack, '@');
    push(stack, '#');

    print_stack(stack);

    printf("pop(): %c\n", pop(stack));

    push(stack, '&');
    push(stack, '!');

    print_stack(stack);

    printf("top: %c\n", top(stack));

    return 0;
}

char push(char* stack, char c)
{
    *(stack + ++*stack) = c;
    return c;
}

char pop(char* stack)
{
    char c = *(stack + *stack);
    --*stack;
    return c;
}

char top(char* stack)
{
    return *(stack + *stack);
}

void print_stack(char* stack)
{
    for (short i = 1; i <= *stack; ++i) {
        fprintf(stdout, " %c |", *(stack + i));
    }
    putchar('\n');
}

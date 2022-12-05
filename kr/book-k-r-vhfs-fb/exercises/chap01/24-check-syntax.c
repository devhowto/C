// Exercise 1-24. Write a program to check a C program for rudimentary syntax
// errors like unmatched parentheses, brackets and braces. Don't forget about
// quotes, both single and double, escape sequences, and comments. (This
// program is hard if you do it in full generality.)

#include <stdio.h>

#define MAXLEN 500

#define FALSE 0
#define TRUE  1

#define STK_SIZE 100

//
// 0 - not in comment, not in string.
// 1 - in single comment or in single quote constant character.
// 2 - in multi line comment or in double quoted string.
//

short chk_quot(int c, int prev, short quot, short cmnt);
short chk_cmnt(int c, int prev, short cmnt, short quot);

short is_opening_char(int c, short prev_quot);
short is_closing_char(int c, short prev_quot);
short is_match(int opening, int closing);

char push(char c, char* stack);
char pop(char* stack);
char top(char* stack);
void stack_dump(char* stack, short data_type);

void print_error(int unmatched, int lnum);

int main(void)
{
    // For storing the current and previous characters.
    int c,
        prev,
        prev_quot,
        lnum;

    short cmnt,         // Type of comment, none, single line or multiline.
          quot;         // Type of quote, none, single or double.

    char stk_chars[STK_SIZE] = {[0] = '\0'};
    char stk_lnums[STK_SIZE] = {[0] = 0};

    cmnt = quot = 0;

    lnum = 1;

    while ((c = getchar()) != EOF) {

        if ('\n' == c) ++lnum;

        cmnt = chk_cmnt(c, prev, cmnt, quot); // 0, 1, 2
        if (cmnt != 0) {
            prev = c;
            continue;
        }

        quot = chk_quot(c, prev, quot, cmnt); // 0, 1, 2

        // If we are already inside a string, just go one to the
        // next iteration of the loop. If we are not inside a quote
        // or it has just started (this is the opening quote char),
        // we have to check the character.
        if (quot != 0 && prev_quot == quot) {
            //putchar(c);
            prev = c;
            continue;
        }

        // Everything from here on relies on the two `continue`s
        // from the tests above, since they "continue" if we are
        // inside comments or in the middle of strings.

        // Check if it is an "opening" thing.
        if (is_opening_char(c, prev_quot)) {
            push(c, stk_chars);
            push(lnum, stk_lnums);
        }

        // Checks the c is a closing thing.
        if (is_closing_char(c, prev_quot)) {

            if (is_match(c, top(stk_chars))) {
                pop(stk_chars);
                pop(stk_lnums);
            }
            else {
                if (*stk_chars > 0) {
                    print_error(top(stk_chars), top(stk_lnums));
                }
                else {
                    print_error(c, lnum);
                }
            }
        }

        prev = c;
        prev_quot = quot;
    }

    if (*stk_chars> 0) {
        print_error(top(stk_chars), top(stk_lnums));
    }

    return 0;
}


/**
 * Check if we are inside a quote or ended it.
 */
short chk_quot(int c, int prev, short quot, short cmnt)
{
    // If we are inside a comment, we can't possibly be inside quotes.
    if (cmnt != 0) return 0;

    // If we are inside single quote, check if it has ended.
    // We make sure the previous char was not an escape.
    if (quot == 1 && prev != '\\' && c == '\'') return 0;

    // If we are inside double quotes, check if it has ended.
    // We make sure the previous char was not an escape.
    if (quot == 2 && prev != '\\' && c == '"') return 0;

    // If we are inside double quotes, we shall not check if
    // another quote has started, for instance.
    if (quot == 0) {
        // Otherwise, check if a quote has started.
        if (c == '\'') return 1;
        if (c == '"') return 2;
    }

    // This will be returned when we are in the middle of a quoted thing
    // and we still did not find the end of it.
    // Since we found no condition to update the type of quote,
    // just return the current status as it was outside the function.
    return quot;
}


/**
 * Check if we are inside a comment or ended it.
 */
short chk_cmnt(int c, int prev, short cmnt, short quot)
{
    // If we are in quotes, we can't possibly be inside a comment.
    if (quot != 0) return 0;

    // If we are inside a single line comment, check if it has ended.
    if (cmnt == 1 && c == '\n') {
        return 0;
    }

    // If we are inside a multi line comment, check if it has ended.
    if (cmnt == 2 && prev == '*' && c == '/') {
        return 0;
    }

    // Only check for comment start if we are not already inside one.
    if (cmnt == 0) {
        // Otherwise check if a comment has started.
        if (prev == '/' && c == '/') {
            return 1;
        }

        if (prev == '/' && c == '*') {
            return 2;
        }
    }

    // This will be returned when we are in the middle of a comment
    // and we still did not find the end of it.
    // Since we found no condition to update the type of comment,
    // just return the current status as it was outside the function.
    return cmnt;
}


char push(char c, char* stack)
{
    *(stack + ++*stack) = c;
    return c;
}

char pop(char* stack)
{
    char top = *(stack + *stack);
    --*stack;
    return top;
}

char top(char* stack)
{
    return *(stack + *stack);
}

void stack_dump(char* stack, short data_type)
{
    for (int i = 1; i <= *stack; ++i) {
        if (data_type == 0)
            fprintf(stdout, "%5c ", *(stack + i));
        else
            fprintf(stdout, "%5d ", *(stack + i));
    }

    putchar('\n');
}

short is_opening_char(int c, short prev_quot) {
    if ((c == '"' && prev_quot != 2)
            || (c == '\'' && prev_quot != 1)
            || c == '('
            || c == '{'
            || c == '['
            || c == '<') {

        return TRUE;
    }

    return FALSE;
}

short is_closing_char(int c, short prev_quot) {

    if (('"' == c && 2 == prev_quot)
            || ('\'' == c && 1 == prev_quot)
            || ')' == c
            || '}' == c
            || ']' == c
            || '>' == c) {

        return TRUE;
    }

    return FALSE;
}

short is_match(int opening, int closing) {
    if ((('"' == opening || '\'' == opening) && closing == opening)
            || (')' == opening && closing == '(')
            || ('}' == opening && closing == '{')
            || (']' == opening && closing == '[')
            || ('>' == opening && closing == '<')) {

        return TRUE;
    }

    return FALSE;
}

void print_error(int unmatched, int lnum) {
    fprintf(stdout, "Error: unmatched %c on line %d.\n", unmatched, lnum);
}


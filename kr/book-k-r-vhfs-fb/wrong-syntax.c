// Exercise 1-24. Write a program to check a C program for rudimentary syntax
// errors like unmatched parentheses, brackets and braces. Don't forget about
// quotes, both single and double, escape sequences, and comments. (This
// program is hard if you do it in full generality.)

#include <stdio.h>
#include "lib/helpers.h" /* Includes our own helper functions. */

#define MAXLINELEN 200
#define STACKSIZE 20

#define FALSE 0
#define TRUE  1

#define TYPE_CMT_NONE   0 // Not inside a comment at all.
#define TYPE_CMT_SINGLE 1 // Inside a single line comment.
#define TYPE_CMT_MULTI  2 // Inside a multi-line comment.

#define ERR_NONE 0
#define ERR_UNMATCHED_BRACKET 1

char push(char c, char* stack);
char pop(char* stack);
char top(char* top);
void print_stack(char* chars, short type);


short check_comment_start(char* line);
short check_comment_end(char* line, short type_cmt);
short check_comment_single_end(char* line);
short check_comment_multi_end(char* line);
short check_string_delimiter(char* line);

short check(char c, char* stk_chars, char* stk_lnum, short lnum);

short is_matching_pair(char c, char t);
short is_opening_pair(char c, char* stk_chars);
short is_closing_pair(char c, char* stk_chars);
short is_closing_bracket(char c, char* stk_chars);
short is_opening_dq(char c, char* stk);
short is_opening_sq(char c, char* stk);
short is_closing_dq(char c, char* stk);
short is_closing_sq(char c, char* stk);

int main(void)
{
    int i, c, len, lnum;
    char line[MAXLINELEN];
    short type_cmt,
          is_in_str,
          err;

    lnum = 1;

    is_in_str = err = FALSE;
    type_cmt = TYPE_CMT_NONE;

    char stk_chars[STACKSIZE] = {[0] = 0, [1] = '\0'};
    char stk_lnum[STACKSIZE] = {[0] = 0, [1] = '\0'};

    while ((len = get_line(line, MAXLINELEN)) > 0) {
        i = 0;
        while ((c = *(line + i)) != '\n') {
            if ((is_in_str == FALSE) && (type_cmt == TYPE_CMT_NONE)) {

                err = check(c, stk_chars, stk_lnum, lnum);

                // Check if string has begun.
                is_in_str = check_string_delimiter(line + i);

                //printf("OUT everything\n");
                //putchar(c);

                // Comments are never inside strings, so, only check for comment
                // start if we are not inside a string.
                if (is_in_str == FALSE) {
                    type_cmt = check_comment_start(line + i);
                }
            }
            else if (is_in_str == TRUE) {
                // Check if string has ended.
                if (check_string_delimiter(line + i) == TRUE) {
                    is_in_str = FALSE;
                    // If it has indeed ended, call check for ".
                    err = check(c, stk_chars, stk_lnum, lnum);
                }
                else {
                    //printf("IN STRING\n");
                }
            }
            else if (type_cmt != TYPE_CMT_NONE) {
                // Check if comment as ended.
                if (check_comment_end(line + i, type_cmt) == TRUE) {
                    type_cmt = TYPE_CMT_NONE;
                }
                else {
                    printf("IN COMMENT\n");
                }
            }

            if (err == TRUE) {
                fprintf(stdout, "Unmatched %c on line %d.\n",
                        top(stk_chars), top(stk_chars));
            }
            ++i;
        }
        ++lnum;
        putchar('\n');
    }

    print_stack(stk_chars, 0);
    print_stack(stk_lnum, 1);

    return 0;
}

char push(char c, char* stack)
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

void print_stack(char* stack, short type)
{
    short i;

    for (i = 1; i <= *stack; ++i) {
        if (type == 0) {
            fprintf(stdout, " %5c", *(stack + i));
        }
        else {
            fprintf(stdout, " %5d", *(stack + i));
        }
    }
    putchar('\n');
}

short check_comment_start(char* line)
{
    if (*line == '/' && (*(line + 1) == '*')) {
        return TYPE_CMT_MULTI;
    }
    else if (*line == '/' && (*(line + 1)) == '/') {
        return TYPE_CMT_SINGLE;
    }

    return TYPE_CMT_NONE;
}

short check_comment_end(char* line, short type_cmt)
{
    if (type_cmt == TYPE_CMT_MULTI) {
        return check_comment_multi_end(line);
    }
    else if (type_cmt == TYPE_CMT_SINGLE) {
        return check_comment_single_end(line);
    }

    return TRUE;
}

short check_comment_multi_end(char* line)
{
    if (*line == '*' && *(line + 1) == '/')
        return TRUE;

    return FALSE;
}

short check_comment_single_end(char* line)
{
    if (*(line + 1) == '\n')
        return TRUE;

    return FALSE;
}

short check_string_delimiter(char* line)
{
    return ((*(line - 1) != '\\')) && *line == '"'; // ? TRUE : FALSE;
}

short is_matching_pair(char c, char t)
{
    if ((c == ')' && t == '(')
            || (c == ']' && t == '[')
            || (c == '}' && t == '{')
            || (c == '>' && t == '<')) {
        return TRUE;
    }

    return FALSE;
}

short is_opening_pair(char c, char* stk_chars) {
    if ((c == '(' || c == '{' || c == '[' || c == '<')
            || is_opening_dq(c, stk_chars)
            || is_opening_sq(c, stk_chars)) {

        return TRUE;
    }

    return FALSE;
}

short is_closing_pair(char c, char* stk_chars)
{
    if (is_closing_bracket(c, stk_chars)
        || is_closing_dq(c, stk_chars)
        || is_closing_sq(c, stk_chars)) {

        return TRUE;
    }

    return FALSE;
}

short is_closing_bracket(char c, char* stk_chars)
{
    return (')' == c) || (']' == c) || ('}' == c) || ('>' == c);
}

short check(char c, char* stk_chars, char* stk_lnum, short lnum) {

    if (is_opening_pair(c, stk_chars)) {
        push(c, stk_chars);
        push(lnum, stk_lnum);
    }
    else if (is_closing_pair(c, stk_chars)) {
        if (is_matching_pair(c, top(stk_chars))) {
            pop(stk_chars);
            pop(stk_lnum);
        }
    }

    return -1;
}

/**
 * A double quote is an opening one if the stack of characters
 * doesn't already contain a double quote as its top. If it does, and c
 * is a double quote, than this is definitely a closing one.
 */
short is_opening_dq(char c, char* stk)
{
    return c == '"' && top(stk) != '"';
}

/**
 * A sing quote is an opening one if the stack of characters
 * doesn't already contain a single quote as its top. If it does, and c
 * is a single quote, than this is definitely a closing one.
 */
short is_opening_sq(char c, char* stk)
{
    return c == '\'' && top(stk) != '\'';
}

short is_closing_dq(char c, char* stk)
{
    return (c == '"' && top(stk) == c); // ? TRUE : FALSE;
}

short is_closing_sq(char c, char* stk)
{
    return (c == '\'' && top(stk) == c); // ? TRUE : FALSE;
}

// vim: set foldmethod=syntax:


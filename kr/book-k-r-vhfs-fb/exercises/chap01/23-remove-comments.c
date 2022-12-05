// Exercise 1-23. Write a program to remove all comments from a C program.
// Don't forget to handle quoted strings and character constants properly. C
// comments don't nest.

#include <stdio.h> // Includes the standard INPUT/OUTPUT library.
#include "lib/helpers.h" /* Includes our own helper functions. */

#define MAXLEN 200

#define FALSE 0
#define TRUE  1

#define TYPE_CMT_NONE   0 // Not inside a comment at all.
#define TYPE_CMT_SINGLE 1 // Inside a single line comment.
#define TYPE_CMT_MULTI  2 // Inside a multi-line comment.

void remove_comments(char* line, short* type_cmt, short* is_in_str );
short check_comment_start(char* line);
short check_comment_single_end(char* line);
short check_comment_multi_end(char* line);

int main(void)
{

    int len;
    short is_in_str,
          type_cmt;
    char line[MAXLEN];

    is_in_str = FALSE;
    type_cmt = TYPE_CMT_NONE;

    while ((len = get_line(line, MAXLEN)) > 0) {
        remove_comments(line, &type_cmt, &is_in_str);
        fprintf(stdout, "%s", line);
    }

    return 0;
}

/*
 * If pos_cmt is -1, we are not in a comment (and not in a multiline comment).
 * If pos_cmt is 0, it means the privous line had a non-finished multiline
 * comment so we know this next line is still part of a comment opened in
 * the previous line.
 */

void remove_comments(char* line, short* type_cmt, short* is_in_str )
{
    int i, pos_cmt;

    i = 0;
    pos_cmt = (*type_cmt == TYPE_CMT_MULTI) ? 0 : -1;

    while (*(line + i) != '\n') {

        if (*is_in_str == TRUE) {
            if (*(line + i) == '"') {
                *is_in_str = FALSE;
            }
        }
        else if (pos_cmt == -1 && *(line + i) == '"') {
            *is_in_str = TRUE;
        }
        else {
            // Check if we are inside a comment of if one begins right now.
            if (pos_cmt == -1
                && (*type_cmt = check_comment_start(line + i)) != TYPE_CMT_NONE) {

                pos_cmt = i;
                *(line + i) = '@';
            }

            // If we ARE inside a comment.
            if (pos_cmt > -1) {

                if (*type_cmt == TYPE_CMT_SINGLE && check_comment_single_end(line + i)) {
                    pos_cmt = -1;
                    *type_cmt = TYPE_CMT_NONE;
                }
                else if (*type_cmt == TYPE_CMT_MULTI && check_comment_multi_end(line + i)) {
                    pos_cmt = -1;
                    *type_cmt = TYPE_CMT_NONE;
                    *(line + i + 1) = '@';
                }

                *(line + i) = '@';
            }
        }

        ++i;
    }
}

short check_comment_start(char* line) {

    if (*line == '/' && (*(line + 1) == '*')) {
        return TYPE_CMT_MULTI;
    }
    else if (*line == '/' && (*(line + 1)) == '/') {
        return TYPE_CMT_SINGLE;
    }

    return TYPE_CMT_NONE;
}

short check_comment_multi_end(char* line)
{
    if (*line == '*' && *(line + 1) == '/')
        return TRUE;

    return FALSE;
}

short check_comment_single_end(char* line)
{
    if (*line == '\n')
        return TRUE;

    return FALSE;
}


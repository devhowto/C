//
// Exercise 1-16. Revise the main routine of the longest-line program so it will
// correctly print the length of arbitrary long input lines, and as much as
// possible of the text.
//



// 19:11:16 Fernando-Basso | "Exercise 1-16. Revise the main routine of the longest-line   
//                         | program so it will correctly print the length of arbitrary long
//                         | input lines, and as much as possible of the text.
// 19:11:40 Fernando-Basso | That means they want me to perhaps not keep adding chars to the
//                         | line array, but still count the length?
// 19:15:16            atk | Fernando-Basso: I was never quite sure what this question meant
//                         | by "as much as possible of the text" and I have never heard this
//                         | channel come to a consensus on it, and I don't think there have
//                         | ever been any official statements from the authors, so it's
//                         | totally up to you how to answer that. But from what I recall, the
//                         | book hasn't taught you about allocated storage at that point so
//                         | my best guess would be to just
// 19:15:18            atk | have a big-ish buffer and hold a reasonable number of characters
//                         | (enough to provide some context but not so much that a standard
//                         | terminal will be filled with 30 lines).
// 19:16:36            atk | Fernando-Basso: but you are right, they certainly want you to
//                         | count the length whether you've filled your array or not.
// 19:16:48 Fernando-Basso | Dynamic memory allocation was my fist though. But then I figured
//                         | they probably wanted us to solve it with what had been taught so
//                         | far in the book.
// 19:17:40            atk | In retrospect, I think there WAS a consensus on this one.
// 19:17:58            atk | Yeah, the book hasn't taught you any of that yet, so they DO mean
//                         | "a big buffer".
// 19:18:22            atk | fill it, don't overfill it, but keep track of the character count
//                         | either way.


#include <stdio.h>

// Make buffer len small so it is easier to test.
#define MAXLEN 10 // Maximum input line length

/**
 * FUNCTION PROTOTYPES
 */
int getline(char line[], int lim);
void copy(char from[], char to[]);

// Prints the longest input line.
int main(void)
{
    int len;                // current line length
    int max;                // max len so far
    char line[MAXLEN];      // current input line
    char longest[MAXLEN];   // longest line saved here

    max = 0;

    while ((len = getline(line, MAXLEN)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(line, longest);
        }
    }

    // If max is > 0, then there was at least one line.
    if (max > 0)
        printf("Longest line:\n%s", longest);

    return 0;
}


/**
 * FUNCTION DEFINITIONS
 */

/**
 * getline: Reads a line into s; returns length.
 *
 * This function returns the length of the string, but it also makes
 * the string available in the calling function since s is an array.
 */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        // Only keep copying chars if the number of chars (i) is less
        // than lim - 1 so we don't overfill it. Still, keep incrementing
        // i so we show any length, but store only so much text as lim.
        if (i < lim - 1)
            s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}


/**
 * copy: Copy 'from' into 'to'; Assumes 'to' is big enough.
 */
void copy(char from[], char to[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\n')
        ++i;
}



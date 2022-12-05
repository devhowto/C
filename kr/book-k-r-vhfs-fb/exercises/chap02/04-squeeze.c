// Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes
// each character in s1 that matches any character in the string s2 .

#include <stdio.h>

/* Delete all c from s. */
void squeeze(char s1[], char s2[]);

#define LIM 50

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: squeze \"input string\" \"chars to remove\"\n");
        return 1;
    }

    // It is possible to modify the contents of argv.
    squeeze(argv[1], argv[2]);
    printf(argv[1]);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (k = 0; s2[k] != '\0'; k++) {
        for (i = j = 0; s1[i] != '\0'; i++) {
            if (s1[i] != s2[k]) {
                s1[j++] = s1[i];
            }
        }
        s1[j] = '\0';
    }
}


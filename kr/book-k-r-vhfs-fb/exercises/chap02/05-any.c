// Exercise 2-5. Write the function any(s1,s2) , which returns the first
// location in a string s1 where any character from the string s2 occurs, or -1
// if s1 contains no characters from s2. (The standard library function
// strpbrk does the same job but returns a pointer to the location.)

#include <stdio.h>

int any(char s1[], char s2[]);

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "We need two arguments. Bailing out...\n");
        return -1;
    }

    printf("%d\n", any(argv[1], argv[2]));

    return 0;
}

int any(char s1[], char s2[])
{
    int i, k;

    for (i = 0; s1[i] != '\0'; i++) {
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                return i;
            }
        }
    }

    return -1;
}


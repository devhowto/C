/**
 * We took the leap year and ‘remainder’ operator explanation
 * and created this program and used enums as well just to practice.
 *
 * Test it like this:
 *
 *   $ for year in {1900..2020} ; do ./devel "$year" ; done
 */


#include <stdio.h>
#include <stdlib.h>

enum mybool { NO, YES };

enum mybool is_leap_year(int year);

int main(int argc, char *argv[])
{
    int year;

    if (argc != 2) {
        fprintf(stderr, "You need to pass the year number.\n");
        return 1;
    }

    // Assume the input is an integer.
    year = atoi(*(argv + 1));

    if (is_leap_year(year)) {
        fprintf(stdout, "%d is a leap year!\n", year);
    }
    else {
        fprintf(stdout, "%d is not a leap year...\n", year);
    }

    return 0;
}

enum mybool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0
        ? YES
        : NO;
}


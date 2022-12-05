// Exercise 2-1. Write a program to determine the ranges of char , short , int,
// and long variables, both signed and unsigned , by printing appropriate
// values from standard headers and by direct computation. Harder if you
// compute them: determine the ranges of the various floating-point types.

// Various floating point types:
//   - float
//   - double
//   - long double


#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("%25s: %20d, %25s: %20d\n", "unsigned char min", 0, "unsigned char min", UCHAR_MAX);
    printf("%25s: %20d, %25s: %20d\n", "signed char max", SCHAR_MIN, "signed char min", SCHAR_MAX);

    printf("%25s: %20d, %25s: %20d\n", "unsigned int min", 0, "unsigned int max", UINT_MAX);
    printf("%25s: %20d, %25s: %20d\n", "signed int min", INT_MIN, "signed int max", INT_MAX);

    printf("%25s: %20ld, %25s: %20ld\n", "unsinged long min", 0L, "unsigned long max", ULONG_MAX);
    printf("%25s: %20ld, %25s: %20ld\n", "signed long min", LONG_MIN, "signed long max", LONG_MAX);

    printf("%25s: %20e, %25s: %20e\n", "signed float min", FLT_MIN, "signed long max", FLT_MAX);
    printf("%25s: %20e, %25s: %20e\n", "signed double min", DBL_MIN, "signed double max", DBL_MAX);
    printf("%25s: %20Le, %25s: %20Le\n", "signed long double min", LDBL_MIN, "signed double max", LDBL_MAX);

    return 0;
}


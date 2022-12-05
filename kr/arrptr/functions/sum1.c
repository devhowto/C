#include <stdio.h>

short add(short, short);

int main(void) {

    short res;

    //
    // Declares a pointer to a function.
    //
    short (*fnptr)(short, short);

    //
    // Store the address of the function to the pointer.
    //
    fnptr = &add;

    //
    // Dereferences the pointer to the function in order to invoke it.
    //
    res = (*fnptr)(3, 4);

    printf("%hd\n", res);

    return 0;
}


short add(short a, short b) {
    return a + b;
}

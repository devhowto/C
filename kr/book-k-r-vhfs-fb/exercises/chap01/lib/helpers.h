
/**
 * Read input up to \n into s up to lim - 1 chars.
 */
int get_line(char s[], int lim);

/**
 * Shifts `step` characters to the right, starting from `ini` position
 * and fills the “emptied” space with `fill` character.
 */
int shift_r(char* input, int len, int ini, short step, char fill);

/**
 * Converts alphabetic characters to lower case.
 */
int mylower(int c);

/**
 * Converts alphabetic characters to upper case.
 */
int myupper(int c);


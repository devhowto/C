#include <stdio.h>

#define LEN 5

short* gen(short len) {
  static short xs[LEN] = { 1, 2, 3 };

  return xs;
}

int main() {
  short i;
  short* res = gen(3);

  for (i = 0; i < 3; ++i)
    printf("%hd\n", *(res + i));

  return 0;
}

#include <stdio.h>

void fn(char s[]) {
  printf("%ld\n", sizeof s);
}

int main() {
  char str[4] = { 'T', 'u', 'x', '\0' };

  printf("%ld\n", sizeof str);

  fn(str);

  return 0;
}


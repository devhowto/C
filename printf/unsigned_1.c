#include <stdio.h>

void nl() {
  printf("%c", '\n');
}

int main() {
  //
  // Order of specifiers matter.
  //
  printf("%uh\n", (unsigned short int)1);
  printf("%hu\n", (unsigned short int)1);

  nl();

  printf("%lu\n", (unsigned long int)1);
  printf("%ld\n", (unsigned long int)1);
}

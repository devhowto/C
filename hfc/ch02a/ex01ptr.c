#include <stdio.h>

//
// p The void * pointer argument is printed in
//   hexadecimal (as if by %#x or %#lx).
//

int main () {
  int *p;
  int x = 3;
  p = &x;

  printf("p addr: %p\n", (void *)p);
  printf("*p val: %i\n", *p);
}

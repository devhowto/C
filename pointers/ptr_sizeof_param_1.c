#include <stdio.h>

void f(char s[])
{
  printf("f: %ld\n", sizeof(s));
  //=> 8
  // Size of pointer to char in my machine
  // at the time of this writing.
}

int main()
{
  char cs[] = "tux";

  printf("main: %ld\n", sizeof(cs));
  //=> 4
  // length of the stringF
  // { 't', 'u', 'x', '\0' }

  f(cs);

  return 0;
}

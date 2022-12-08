#include <stdio.h>

int main ()
{
  char a[] = "z";
  printf("%ld\n", sizeof(a));

  char b[1] = "z";
  printf("%ld\n", sizeof(b));

  // char s[3] = { 'T', 'u', 'x', '\0' };
  // printf("s: %s\n", s);

  // for (short i = 0; i <= 3; ++i)
  //   printf("%c, %i\n", s[i], s[i]);

  int i = 0;
  char c;
  while ((c = a[i++]) != NULL)
    printf("c: %c\n", c);

  return 0;
}


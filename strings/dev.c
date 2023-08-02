#include <stdio.h>

void skip(const char *s) {
  puts(s + 6);
  printf("%s\n", s + 6);
}

int main() {
  char *msg = "Don't call me.";
  skip(msg);
}

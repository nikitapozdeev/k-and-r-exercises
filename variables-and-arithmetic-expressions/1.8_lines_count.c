// Exercise 1.8 from K&R The C Programming Language. 2nd Edition.

#include <stdio.h>

int main() 
{
  int c, lc, tc, sc;
  lc = 0;
  tc = 0;
  sc = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++lc;
    }

    if (c == '\t') {
      ++tc;
    }

    if (c == ' ') {
      ++sc;
    }
  }
  printf("lines: %d\ntabs: %d\nspaces: %d\n", lc, tc, sc);

  return 0;
}
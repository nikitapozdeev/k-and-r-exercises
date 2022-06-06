// Exercise 1.9 from K&R The C Programming Language. 2nd Edition.

#include <stdio.h>

int main() 
{
  int c;
  int sc;

  sc = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++sc;
    } else {
      sc = 0;
    }

    if (sc <= 1) {
      putchar(c);
    }
  }

  return 0;
}
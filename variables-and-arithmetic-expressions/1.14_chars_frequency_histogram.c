// Exercise 1.14 from K&R The C Programming Language. 2nd Edition.

#include <stdio.h>

#define ASCII_LENGTH 256
#define MAX_FREQUENCY 15

int main()
{
  int i;
  int chars[ASCII_LENGTH];

  // clear
  for (i = 0; i < ASCII_LENGTH; i++) {
    chars[i] = 0;
  }

  int c;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\n' && c != '\t') {
      ++chars[c];
    }
  }

  int j;
  printf("char | frequency\n");
  
  for (i = 0; i < ASCII_LENGTH; ++i) {
    if (chars[i] > 0) {
      printf("%4c |", i);
      for (j = 0; (j < chars[i]) && (j < MAX_FREQUENCY); ++j) {
        putchar('-');
      }
      putchar('\n');
    }
  }

  return 0;
}
// Exercise 1.13 from K&R The C Programming Language. 2nd Edition.

#include <stdio.h>

#define MAX_LEN 20

int main()
{
  int i;
  int wlen[MAX_LEN];

  // clear
  for (i = 0; i < MAX_LEN; ++i) {
    wlen[i] = 0;
  }

  int c, word_len;
  word_len = 0;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\n' && c != '\t') {
      ++word_len;
    } else if (word_len > 0) {
      // truncate to max
      if (word_len >= MAX_LEN) {
        word_len = MAX_LEN;
      }

      ++wlen[word_len - 1];
      word_len = 0;
    }
  }

  // print histogram
  int j;
  printf("word len | words count\n");
  for (i = 1; i <= MAX_LEN; ++i) {
    if (i == MAX_LEN) {
      printf("> %6d |", i);
    } else {
      printf("%8d |", i);
    }
    for (j = 0; j < wlen[i - 1]; ++j) {
      putchar('-');
    }
    printf("\n");
  }

  return 0;
}


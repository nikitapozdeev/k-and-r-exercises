// Exercise 1.17 from K&R The C Programming Language. 2nd Edition.

#include <stdio.h>

#define MAXLINE 1000
#define MINLEN 80

int get_line(char linef[], int maxline);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > MINLEN) {
      printf("%s\n", line);
    }
  }

  return 0;
}

int get_line(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}
// Exercise 1.20 from K&R The C Programming Language. 2nd Edition.

#include <stdio.h>

#define MAXLINE 1000
#define TABSIZE 2

int get_line(char linef[], int maxline);
void print_detab(char line[]);

int main()
{
  int len;
  int max;
  char line[MAXLINE];
  max = 0;

  while ((len = get_line(line, MAXLINE)) > 0) {
    print_detab(line);
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

void print_detab(char line[])
{
  int i;
  int j;
  for (i = 0; line[i] != '\0'; ++i) {
    if (line[i] == '\t') {
      for (j = 0; j < TABSIZE; j++) {
        putchar(' ');
      }
    } else {
      putchar(line[i]);
    }
  }
}
// Exercise 1.18 from K&R The C Programming Language. 2nd Edition.
// FIXME: not working.
#include <stdio.h>

#define MAXLINE 1000

int get_line(char linef[], int maxline);
void trim_print(char line[], int len);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    trim_print(line, len);
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

void trim_print(char line[], int len) 
{
  if (len > 0 && line[0] == '\0') {
    return;
  }

  int i, prev_char, is_empty;
  
  is_empty = 1;
  prev_char = -1;

  for (i = 0; i < len; ++i) {
    if (line[i] != ' ' && line[i] != '\t') {
      is_empty = 0;
    }

    if (!is_empty) {
      if ((prev_char == ' ' || prev_char == '\t') && (line[i] == ' ' || line[i] == '\t')) {
        ;
      } else {

        putchar(line[i]);
      }
    }

    prev_char = line[i];
  }
}
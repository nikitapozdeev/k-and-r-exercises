// Exercise 1.19 from K&R The C Programming Language. 2nd Edition.

#include <stdio.h>

#define MAXLINE 1000

int get_line(char linef[], int maxline);
void reverse(char s[]);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    reverse(line);
    printf("%s\n", line);
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

void reverse(char s[])
{
  int len = 0;
  while (s[len] != '\0') {
    ++len;
  }

  if (len == 0) {
    return;
  }

  int i, j;
  int temp;
  
  for (i = 0; i < len - 1 - i; ++i) {
    temp = s[i];
    s[i] = s[len - 1 - i];
    s[len - 1 - i] = temp;
  }
}
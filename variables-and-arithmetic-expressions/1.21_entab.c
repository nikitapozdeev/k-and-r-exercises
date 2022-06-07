// Exercise 1.21 from K&R The C Programming Language. 2nd Edition.

#include <stdio.h>

#define MAXLINE 1000
#define TABSIZE 2

int get_line(char linef[], int maxline);
void print_entab(char line[]);
int get_ns(char line[], int from);

int main()
{
  int len;
  int max;
  char line[MAXLINE];
  max = 0;

  while ((len = get_line(line, MAXLINE)) > 0) {
    print_entab(line);
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

void print_entab(char line[])
{
  int i, j;
  int ns, nt;

  for (i = 0; line[i] != '\0'; ++i) {
    if (line[i] == ' ') {
      ns = get_ns(line, i);
      nt = ns / TABSIZE;
      i = i + ns - 1;
      for (j = 0; j < nt; ++j) {
        putchar('\t');
        ns = ns - TABSIZE;
      }

      for (j = 0; j < ns; ++j) {
        putchar(' ');
      }
    } else {
      putchar(line[i]);
    }
  }
}

// returns spaces sequence count from index
int get_ns(char line[], int from)
{
  int count;
  int i;

  count = 0;
  for (i = from; line[i] == ' '; ++i) {
    ++count;
  }

  return count;
}
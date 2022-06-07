// Exercise 1.16 from K&R The C Programming Language. 2nd Edition.

/*
  According to text of exercise we can modify only main function,
  so i can't touch get_line function. 
  Maybe it's not the best solution, but it seems to work
  if I didn't miss some tricky test cases.
*/

#include <stdio.h>

#define MAXLINE 1000

int get_line(char linef[], int maxline);
void copy(char to[], char fromf[]);
int is_maxsize_exceeded(char line[], int len);

int main()
{
  int linelen, chunklen;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];
  char temp[MAXLINE];

  max = 0;
  linelen = 0;

  // read by chunks of MAXLINE size 
  while ((chunklen = get_line(line, MAXLINE)) > 0) {
    // compute full line length at current step
    linelen = linelen + chunklen;

    if (is_maxsize_exceeded(line, chunklen)) {
      // save first exceeded chunk
      if (linelen == MAXLINE - 1) {
        copy(temp, line);
      }
    } else {
      if (linelen > max) {
        max = linelen;
        // if it's not the first chunk then
        // copy from temp buffer
        if (linelen < MAXLINE - 1) {
          copy(longest, line);
        } else {
          copy(longest, temp);
        }
      }
      linelen = 0;
    }
  }

  if (max > 0) {
    printf("%s", longest);
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

void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}

int is_maxsize_exceeded(char line[], int len)
{
  // if line ended without new line character,
  // then char buffer size exceeded
  return (len == MAXLINE - 1) && (line[len - 1] != '\n');
}
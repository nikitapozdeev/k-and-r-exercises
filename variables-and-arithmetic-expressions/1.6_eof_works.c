// Exercise 1.6 from K&R The C Programming Language. 2nd Edition.

#include <stdio.h>

int main()
{
  printf("Is EOF reached? %d\n", (getchar() != EOF));
  return 0;
}
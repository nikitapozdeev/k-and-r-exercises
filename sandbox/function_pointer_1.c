#include <stdio.h>

typedef int (*operation)(int, int);

int mul(int a, int b)
{
  return a * b;
}

int add(int a, int b)
{
  return a + b;
}

void do_operation(int (*operation)(int, int), int a, int b)  
{
  int result = operation(a, b);
  printf("operation result = %d\n", result);
}

int main()
{
  do_operation(add, 3, 3);
  do_operation(mul, 3, 3);
  return 0;
}
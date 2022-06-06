// Exercise 1.5 from K&R The C Programming Language. 2nd Edition.

#include <stdio.h>

int main() 
{
  int fahr;
  
  for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
    printf("%3d %6.f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  }
}
// Exercise 1.4 from K&R The C Programming Language. 2nd Edition.

#include <stdio.h>

int main() 
{
  printf("Celsius -> Fahrenheits conversion table\n");

  float fahr, celsius;
  int lower, upper, step;

  lower = -40;
  upper = 40;
  step = 5;

  celsius = lower;
  while (celsius <= upper) {
    fahr = (9.0 / 5.0) * (celsius + 32);
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  } 
}
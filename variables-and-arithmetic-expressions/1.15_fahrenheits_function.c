// Exercise 1.15 from K&R The C Programming Language. 2nd Edition.

#include <stdio.h>

float fahrenheitsToCelsius(float fahrenheits);

int main() 
{
  printf("Fahrenheit -> Celcius convertion table\n");

  float fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    printf("%3.0f %6.1f\n", fahr, fahrenheitsToCelsius(fahr));
    fahr = fahr + step;
  }

  return 0;
}

float fahrenheitsToCelsius(float fahrenheits)
{
  return (5.0 / 9.0) * (fahrenheits - 32.0);
}
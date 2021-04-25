#include "math.h"

int factorial_recursive(int n)
{
  if (n <= 1)
  {
    return 1;
  }
  return n * factorial_recursive(n - 1);
}

int factorial_iterative(int n)
{
  int count = 1;
  int product = 1;
  while (count <= n)
  {
    product *= count;
    count++;
  }
  return product;
}

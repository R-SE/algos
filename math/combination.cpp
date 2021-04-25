#include <iostream>
#include <math.h>
#include "math.h"

/*
The formula for the number of unique combinations possible by selecting r items from n items is:
nCr = n! / (r! * (n - r)!)
*/
int combination_iterative(int n, int r)
{
  return factorial_iterative(n) / (factorial_iterative(r) * factorial_iterative(n - r));
}

/*
We can use Pascal's Triangle to calculate nCr.
nCr = (n-1)C(r-1) + (n-1)C(r)
*/
int combination_recursive(int n, int r)
{
  // There's only 1 way to choose x items from x items,
  // and only 1 way to choose 0 items from x items.
  if (n == r || r == 0)
  {
    return 1;
  }

  return combination_recursive(n - 1, r - 1) + combination_recursive(n - 1, r);
}

// We can calculate just the one row we need from Pascal's Triangle.
int combination_pascals_triangle_single_row(int n, int r)
{
  int combos = 1;

  for (int i = 0; i < r; i++)
  {
    combos = combos * (n - i) / (i + 1);
  }

  return combos;
}

int main()
{
  int x = combination_iterative(10, 5);
  int y = combination_recursive(10, 5);
  int z = combination_pascals_triangle_single_row(10, 5);
  std::cout << x << ' ' << y << ' ' << z;
}
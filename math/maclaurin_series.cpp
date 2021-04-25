#include <iostream>
#include <math.h>
#include "math.h"

/*
MacLaurin Series is a progression of n terms of form:
x^0/0! + x^1/1! + x^2/2! + x^3/3! + x^4/4! + ... + x^n-1 / (n - 1)!
*/

double maclaurin_series_recursive(int x, int n)
{
  if (n == 0)
  {
    return 1;
  }
  else if (n == 1)
  {
    return x;
  }

  return pow(x, n - 1) / factorial_iterative(n - 1) + maclaurin_series_recursive(x, n - 1);
}

double maclaurin_series_iterative(int x, int n)
{
  double result = x;

  while (n > 1)
  {
    result += pow(x, n - 1) / factorial_iterative(n - 1);
    n--;
  }

  return result;
}

/*
The progression above can have common terms factored out repeatedly to give the form:

1+x/1 [ 1+x/2 [ 1+x/3 [ 1+x/4 [ ... 1+x/n ]]]]
*/
double maclaurin_series_horners_rule(double x, double n)
{
  double result = 1;
  n--;

  while (n > 0)
  {
    result = (1 + (x / n) * result);
    n--;
  }

  return result;
}

int main()
{
  double x = maclaurin_series_iterative(1, 10);
  double y = maclaurin_series_horners_rule(1, 10);
  std::cout << x << ' ' << y;
}
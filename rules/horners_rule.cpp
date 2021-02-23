#include <iostream>
#include <vector>

long long horners_rule(std::vector<int> &coefs, int x)
{
  long long sum = 0;
  for (int i = coefs.size() - 1; i >= 0; i--)
  {
    sum = coefs[i] + x * sum;
  }
  return sum;
}

int main()
{
  // To simplify things, we will assume that every power is represented,
  // and our vector is structured such that the index represents the power,
  // and the value represents the coefficient.
  // e.g. f(x) = 55 + 7x + 23x^2 + 235x^3 + 23x^4 + 55x^5 + x^6 + 8x^7 + 54x^8
  std::vector<int> term_coefficients{55, 7, 23, 235, 23, 55, 1, 8, 54};
  long long answer = horners_rule(term_coefficients, 3);
  std::cout << answer;
}

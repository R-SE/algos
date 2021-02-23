#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>

long long naive_polynomial_evaluation(std::vector<int> &coefs, int x)
{
  long long sum = 0;
  for (int i = 0; i < coefs.size(); i++)
  {
    sum += coefs[i] * pow(3, i);
  }
  return sum;
}

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
  long long answer;

  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 9999999; i++)
  {
    answer = horners_rule(term_coefficients, 3);
  }
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  std::cout << answer << " computed in " << duration.count() << " milliseconds." << std::endl;

  start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 9999999; i++)
  {
    answer = naive_polynomial_evaluation(term_coefficients, 3);
  }
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  std::cout << answer << " computed in " << duration.count() << " milliseconds." << std::endl;
}

int sum_of_n_natural_numbers_recursive(int n)
{
  if (n == 0)
  {
    return 0;
  }
  return n + sum_of_n_natural_numbers_recursive(n - 1);
}

int sum_of_n_natural_numbers_iterative(int n)
{
  int count = 1;
  int sum = 0;
  while (count <= n)
  {
    sum += count;
    count++;
  }
  return sum;
}

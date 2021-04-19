int power_recursive(int base, int exponent)
{
  if (exponent == 0)
  {
    return 1;
  }
  if (exponent == 1)
  {
    return base;
  }
  return base * power_recursive(base, exponent - 1);
}

int power_recursive_2(int base, int exponent)
{
  if (exponent == 0)
  {
    return 1;
  }
  if (exponent == 1)
  {
    return base;
  }
  if (exponent % 2 == 1)
  {
    return base * power_recursive_2(base * base, (exponent - 1) / 2);
  }
  else
  {
    return power_recursive_2(base * base, exponent / 2);
  }
}

int power_iterative(int base, int exponent)
{
  int power = 1;
  while (exponent > 0)
  {
    power *= base;
    exponent--;
  }

  return power;
}

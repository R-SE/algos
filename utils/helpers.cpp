#include <iostream>
#include "helpers.h"

void print_nums(int nums[], int length)
{
  for (size_t i = 0; i < length; i++)
  {
    std::cout << nums[i] << ", ";
  }
  std::cout << std::endl;
}

void print_nums(std::vector<int> nums)
{
  for (int &num : nums)
  {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
}

void print_nums(std::deque<int> nums)
{
  for (int &num : nums)
  {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
}
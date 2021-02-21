#include <iostream>
#include <deque>
#include "../utils/helpers.h"

std::deque<int> merge_sort(std::deque<int> nums)
{
  const int size = nums.size();
  if (size <= 1)
  {
    return nums;
  }

  const int midpoint = size / 2;
  std::deque<int> nums_1(nums.begin(), nums.begin() + midpoint);
  std::deque<int> nums_2(nums.begin() + midpoint, nums.end());
  nums_1 = merge_sort(nums_1);
  nums_2 = merge_sort(nums_2);

  std::deque<int> nums_3;

  // When both deques have elements, compare and insert the smaller element into the new deque.
  while (nums_1.size() && nums_2.size())
  {
    if (nums_1.front() < nums_2.front())
    {
      nums_3.push_back(nums_1.front());
      nums_1.pop_front();
    }
    else if (nums_1.front() > nums_2.front())
    {
      nums_3.push_back(nums_2.front());
      nums_2.pop_front();
    }
    else
    {
      nums_3.push_back(nums_1.front());
      nums_3.push_back(nums_2.front());
      nums_1.pop_front();
      nums_2.pop_front();
    }
  }

  // Find the deque with elements left and throw them into the new deque.
  while (nums_1.size())
  {
    nums_3.push_back(nums_1.front());
    nums_1.pop_front();
  }
  while (nums_2.size())
  {
    nums_3.push_back(nums_2.front());
    nums_2.pop_front();
  }

  return nums_3;
}

int main()
{
  std::deque<int> nums{3, 41, 52, 26, 38, 57, 9, 49};
  std::deque<int> answer = merge_sort(nums);
  print_nums(answer);
}

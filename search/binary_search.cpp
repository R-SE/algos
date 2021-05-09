#include <iostream>
#include <vector>

int binary_search(std::vector<int> &nums, int target)
{
  int start = 0;
  int end = nums.size() - 1;
  int midpoint;

  while (start <= end)
  {
    midpoint = (start + end) / 2;
    const int value = nums[midpoint];
    if (value == target)
    {
      return midpoint;
    }

    if (value > target)
    {
      end = midpoint - 1;
    }
    else
    {
      start = midpoint + 1;
    }
  }

  return -1;
}

int main()
{
  std::vector<int> nums{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int answer = binary_search(nums, 0);
  std::cout << answer;
}
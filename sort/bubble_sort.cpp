#include <vector>
#include "../utils/helpers.h"

void bubble_sort(std::vector<int> &nums)
{
  for (size_t i = 0; i < nums.size(); i++)
  {
    for (size_t j = 1; j < nums.size() - i; j++)
    {
      if (nums[j] < nums[j - 1])
      {
        int temp = nums[j];
        nums[j] = nums[j - 1];
        nums[j - 1] = temp;
      }
    }
  }
}

int main()
{
  std::vector<int> nums{6, 9, -3, 20, 55, 2, 11, 13};
  bubble_sort(nums);
  print_nums(nums);
}
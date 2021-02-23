#include <vector>
#include "../utils/helpers.h"

// Popular style - largest number will bubble its way to the right with each iteration,
// creating a sorted subset at the end of the array.
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

// Style presented in book - smallest number will bubble its way to the left with each iteration,
// creating a sorted subset at the start of the array.
void bubble_sort_backwards(std::vector<int> &nums)
{
  const size_t last_index = nums.size() - 1;
  for (int i = 0; i < last_index; i++)
  {
    for (int j = last_index; j > i; j--)
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

// We can use a variable to keep track of whether we performed any swaps in any given loop.
// If we encounter no swaps, then we know we can return early because the list is already sorted.
void bubble_sort_backwards_with_check(std::vector<int> &nums)
{
  const size_t last_index = nums.size() - 1;
  bool swap;
  for (int i = 0; i < last_index; i++)
  {
    swap = false;
    for (int j = last_index; j > i; j--)
    {
      if (nums[j] < nums[j - 1])
      {
        swap = true;
        int temp = nums[j];
        nums[j] = nums[j - 1];
        nums[j - 1] = temp;
      }
    }

    if (!swap)
    {
      return;
    }
  }
}

int main()
{
  std::vector<int> nums{6, 9, -3, 20, -10, 55, 2, 11, 13, 6};
  bubble_sort_backwards(nums);
  print_nums(nums);
  bubble_sort_backwards_with_check(nums);
}
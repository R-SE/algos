#include "helpers.h"

void insertion_sort(int nums[], int length, bool descending = false)
{

  for (int i = 1; i < length; i++)
  {
    int key = nums[i];
    int j = i - 1;
    while ((descending ? (key > nums[j]) : (key < nums[j])) && j >= 0)
    {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = key;
  }
  print_nums(nums, length);
}

int main()
{
  int nums[10] = {2, 8, 4, 3, 5, 2, 10, 5, 2, -1};
  const int length = sizeof(nums) / sizeof(nums[0]);
  insertion_sort(nums, length, true);
  insertion_sort(nums, length);
}

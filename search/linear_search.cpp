#include <iostream>

int linear_search(int nums[], int length, int target) {
  for (size_t i = 0; i < length; i++) {
    if (nums[i] == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  int nums[] = {5, 2, 4, 3, 1, -5, 2, 3, 7, 9, 0};
  int nums_length = sizeof(nums) / sizeof(nums[0]);
  const int target {7};
  int answer = linear_search(nums, nums_length, target);
  answer = linear_search(nums, nums_length, 999);
}

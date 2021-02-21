#include <iostream>
#include <vector>

std::vector<int> add_nums(const int nums_a[], const int nums_b[], size_t length) {
  std::vector<int> sum;
  int temp_sum = 0;
  for (int i = length - 1; i >= 0; i--) {
    temp_sum = temp_sum + nums_a[i] + nums_b[i];
    sum.insert(sum.begin(), temp_sum % 2);
    if (temp_sum >= 2) {
      temp_sum = 1;
    } else {
      temp_sum = 0;
    }
  }
  if (temp_sum) {
    sum.insert(sum.begin(), temp_sum);
  }
  return sum;
}

int main() {
  int nums_a[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 0};
  int nums_b[] = {1, 1, 1, 0, 0, 1, 0, 1, 1, 1};
  size_t length = sizeof(nums_a) / sizeof(nums_a[0]);
  std::vector<int> answer = add_nums(nums_a, nums_b, length);
  for (int& element : answer) {
    std::cout << element;
  }
}

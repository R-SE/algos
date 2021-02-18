#include <iostream>
#include <vector>
#include <limits>

void selection_sort(std::vector<int> *nums) {
  int smol = std::numeric_limits<int>::max();
  int idx = -1;
  for (int i = 0; i < nums->size() - 1; i++) {
    for (int j = i + 1; j < nums->size(); j++) {
      if (nums->at(j) < smol) {
        idx = j;
        smol = nums->at(j);
      }
    }
    int temp = nums->at(i);
    nums->at(i) = smol;
    nums->at(idx) = temp;
    smol = std::numeric_limits<int>::max();
    idx = -1;
  }
}

int main() {
  std::vector<int> nums {3, 7, 1, 9, 6, 2, 2, 0, 10, 5};
  selection_sort(&nums);
  for (int &num : nums) {
    std::cout << num << " ";
  }
}


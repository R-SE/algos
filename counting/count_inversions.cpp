#include <iostream>
#include <deque>

std::deque<int> merge_sort_count(const std::deque<int> &nums, int &inversions)
{
  const int size = nums.size();
  if (size <= 1)
  {
    return nums;
  }

  int midpoint = nums.size() / 2;
  std::deque<int> nums_1(nums.begin(), nums.begin() + midpoint);
  std::deque<int> nums_2(nums.begin() + midpoint, nums.end());
  nums_1 = merge_sort_count(nums_1, inversions);
  nums_2 = merge_sort_count(nums_2, inversions);

  std::deque<int> nums_3;

  while (nums_1.size() && nums_2.size())
  {
    if (nums_1.front() < nums_2.front())
    {
      nums_3.push_back(nums_1.front());
      nums_1.pop_front();
    }
    else if (nums_1.front() > nums_2.front())
    {
      inversions += nums_1.size();
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

int count_inversions(const std::deque<int> &nums)
{
  int inversions = 0;
  merge_sort_count(nums, inversions);
  return inversions;
}

int main()
{
  std::deque<int> nums{2, 3, 8, 6, 1};
  int answer;
  answer = count_inversions(nums);
  std::cout << answer << std::endl;

  std::deque<int> nums_2{2, 3, 8, 6, 1};
  answer = count_inversions(nums_2);
  std::cout << answer << std::endl;

  std::deque<int> nums_3{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  answer = count_inversions(nums_3);
  std::cout << answer << std::endl;
}
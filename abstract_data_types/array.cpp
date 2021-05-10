#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

class Array
{
public:
  int size;
  int length;
  int *a;
  Array() = delete;
  Array(int size);
  ~Array();
  void display();
  int add(int num);
  int insert(int num, int idx);
  int deleteAtIdx(int idx);
  int search(int num);
  int get(int idx);
  int set(int idx, int num);
  int getMin();
  int getMax();
  int getSum();
  float getAverage();
  void reverseAtomic();
  void reverseInPlace();
  void leftShift();
  void rightShift();
  void leftRotate();
  void rightRotate();
  void swap(int idx1, int idx2);
  int partition(int start, int end);
  void sort();
  void quick_sort(int start, int end);
  void insertIntoSorted(int num);

private:
  int getMinOrMax(bool isMin);
};

// Constructor for ADT Array.
// Runtime: O(1)
Array::Array(int size)
{
  this->size = size;
  length = 0;
  a = new int[size];
}

// Destructor for ADT Array. Free the dynamically allocated memory used for storing the array data.
Array::~Array()
{
  delete[] a;
}

// Display all items in the array.
// Runtime: O(n)
void Array::display()
{
  std::cout << "Printing elements: ";
  for (int i = 0; i < length; i++)
  {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

// Append to end of the array if there's space, and return number of elements after.
// Runtime: O(1)
int Array::add(int num)
{
  if (length < size)
  {
    a[length++] = num;
  }

  return length;
}

// Insert a number at given index, and return the resulting length.
// Return -1 if failed due to trying to insert out of bounds of array or past current elements.
// Runtime: O(n)
int Array::insert(int num, int idx)
{
  if (idx > length || idx < 0)
  {
    return -1;
  }
  if (idx == length)
  {
    return add(num);
  }
  int pointer = length;
  while (pointer != idx)
  {
    a[pointer] = a[pointer - 1];
    pointer--;
  }
  a[idx] = num;
  return ++length;
}

// Delete number at given index if within range and return new length, otherwise return -1.
// Runtime: Best case O(1), worst case O(n).
int Array::deleteAtIdx(int idx)
{
  if (idx >= length || idx >= size || idx < 0)
  {
    return -1;
  }

  while (idx < length - 1)
  {
    a[idx] = a[idx + 1];
    idx++;
  }
  return --length;
}

// Search through the unsorted array one element at a time, looking for the target number.
// Return index if found, otherwise -1.
// Runtime: Best case O(1), Worst case O(n) from searching through every element of the array.
int Array::search(int num)
{
  for (int i = 0; i < num; i++)
  {
    if (a[i] == num)
    {
      return i;
    }
  }
  return -1;
}

// Get the number at the given index.
// Return -1 if out of bounds.
// Runtime: O(1) Constant time array lookup
int Array::get(int idx)
{
  if (idx < 0 || idx >= length)
  {
    return -1;
  }

  return a[idx];
}

// Set element at given index if within bounds and return new length,
// otherwise do nothing and return -1.
int Array::set(int idx, int num)
{
  if (idx < 0 || idx >= length)
  {
    return -1;
  }

  if (idx == length - 1)
  {
    return add(num);
  }

  a[idx] = num;
  return length;
}

// Get min or max integer of array.
int Array::getMinOrMax(bool isMin)
{
  int num = isMin ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();

  for (int i = 0; i < length; i++)
  {
    if (isMin && a[i] < num)
    {
      num = a[i];
    }
    else if (!isMin && a[i] > num)
    {
      num = a[i];
    }
  }

  return num;
}

int Array::getMin()
{
  return getMinOrMax(true);
}

int Array::getMax()
{
  return getMinOrMax(false);
}

int Array::getSum()
{
  int sum = 0;
  for (int i = 0; i < length; i++)
  {
    sum += a[i];
  }
  return sum;
}

float Array::getAverage()
{
  return (float)getSum() / length;
}

// Reverses the array by allocating a new array,
// filling it with the elements of the old array in reverse order,
// deleting the old array, and setting the new array as the stored array.
// This is so that the entire stored array is overwritten at once,
// to avoid a situation where we've only swapped part of the array.
void Array::reverseAtomic()
{
  int *newArr = new int[size];
  for (int i = length - 1; i >= 0; i--)
  {
    newArr[length - 1 - i] = a[i];
  }
  delete[] a;
  a = newArr;
}

// Reverse the array by swapping elements from both ends.
void Array::reverseInPlace()
{
  int p1 = 0;
  int p2 = length - 1;
  while (p1 < p2)
  {
    int temp = a[p1];
    a[p1++] = a[p2];
    a[p2--] = temp;
  }
}

// Moves all elements one index to the left and drops the first element.
void Array::leftShift()
{
  for (int i = 0; i < length - 1; i++)
  {
    a[i] = a[i + 1];
  }
  length--;
}

// Moves all elements one index to the right and pads array front with a 0.
void Array::rightShift()
{
  for (int i = length; i > 0; i--)
  {
    a[i] = a[i - 1];
  }
  a[0] = 0;
  length++;
}

// Moves all elements one index to the left and
// adds the first element to end of existing elements.
void Array::leftRotate()
{
  int temp = a[0];
  for (int i = 0; i < length - 1; i++)
  {
    a[i] = a[i + 1];
  }
  a[length - 1] = temp;
}

// Moves all elements one index to the right and
// adds the last element to beginning of the array.
void Array::rightRotate()
{
  int temp = a[length - 1];
  for (int i = length - 1; i > 0; i--)
  {
    a[i] = a[i - 1];
  }
  a[0] = temp;
}

void Array::swap(int idx1, int idx2)
{
  int temp = a[idx1];
  a[idx1] = a[idx2];
  a[idx2] = temp;
}

int Array::partition(int start, int end)
{
  int pivotValue = a[end];
  int p1 = start - 1;
  int p2 = start;
  while (p2 < end)
  {
    if (a[p2] < pivotValue)
    {
      p1++;
      swap(p1, p2);
    }
    p2++;
  }
  swap(p1 + 1, end);
  return p1 + 1;
}

// Sort the array in place using quick sort.
void Array::sort()
{
  // First check that we don't have a degenerate case
  // where the array is already sorted or all the elements are same.
  bool isAlreadySorted = true;
  for (int i = 1; i < length; i++)
  {
    if (a[i] < a[i - 1])
    {
      isAlreadySorted = false;
      continue;
    }
  }

  if (isAlreadySorted)
  {
    return;
  }

  quick_sort(0, length - 1);
}

void Array::quick_sort(int start, int end)
{
  if (start >= end)
  {
    return;
  }

  if (end - start == 1)
  {
    if (a[start] > a[end])
    {
      swap(start, end);
    }
    return;
  }

  int pivot = partition(start, end);
  quick_sort(start, pivot - 1);
  quick_sort(pivot + 1, end);
}

// Insert an element into a sorted array,
// dropping the last element if array is full.
void Array::insertIntoSorted(int num)
{
  // First check if num is larger than last element.
  if (num >= a[length - 1])
  {
    add(num);
    return;
  }

  int pointer = length == size ? length - 1 : length;
  while (pointer > 0 && a[pointer - 1] > num)
  {
    a[pointer] = a[pointer - 1];
    pointer--;
  }

  a[pointer] = num;

  length = length == size ? length : length + 1;
}

int main()
{
  Array arr(10);
  arr.add(5);
  arr.display();
  arr.add(6);
  arr.add(7);
  arr.add(8);
  arr.add(11);
  arr.display();
  arr.insert(1, 2);
  arr.display();
  arr.deleteAtIdx(3);
  arr.display();
  std::cout << "Linear searching for num 5 " << arr.search(5) << std::endl;
  std::cout << "Getting min " << arr.getMin() << std::endl;
  std::cout << "Getting max " << arr.getMax() << std::endl;
  std::cout << "Getting sum " << arr.getSum() << std::endl;
  std::cout << "Getting average " << arr.getAverage() << std::endl;
  arr.display();
  std::cout << "Reversing!" << std::endl;
  arr.reverseAtomic();
  arr.display();
  std::cout << "Reversing!" << std::endl;
  arr.reverseInPlace();
  arr.display();
  std::cout << "leftShift!" << std::endl;
  arr.leftShift();
  arr.display();
  std::cout << "rightShift!" << std::endl;
  arr.rightShift();
  arr.display();
  std::cout << "leftRotate!" << std::endl;
  arr.leftRotate();
  arr.display();
  std::cout << "rightRotate!" << std::endl;
  arr.rightRotate();
  arr.display();
  arr.add(9);
  arr.add(-8);
  arr.add(-3);
  arr.add(0);
  arr.display();
  arr.sort();
  arr.display();
  arr.sort();
  arr.insertIntoSorted(7);
  arr.display();
}

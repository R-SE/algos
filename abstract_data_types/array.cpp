#include <iostream>

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
  // private:
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

int main()
{
  Array arr(10);
  arr.add(5);
  arr.display();
  arr.add(6);
  arr.add(7);
  arr.add(8);
  arr.display();
  arr.insert(1, 2);
  arr.display();
  arr.deleteAtIdx(3);
  arr.display();
  std::cout << arr.search(5);
}

**1.1-1:** Collision detection often uses a computed convex hull, e.g. as the outermost bounds of a vehicle, because it is more efficient to determine collision using the simple polygon. Because the convex hull of a vehicle encompasses all points of the vehicle, if the convex hull doesn't collide with something, then none of the points will.

**1.1-2:** Speed and memory usage are two common measures of efficiency, but another important one is power consumption (e.g. in an unmanned aerial vehicle where it's important to minimize battery weight while still allowing for long flight times between charging).

**1.1-3:** A common data structure is a hash map, which can look up or erase an element by key and insert a new element in constant time on average. Its limitations include not being able to be traversed in a sorted order, so searching for an element takes O(n) time. Also, keys must be unique, so there should be some collision resolution mechanism. Lastly, hashmaps will resize when it reaches a percentage of its maximum capacity (e.g. 75%), which involves copying all the elements to a bigger hashmap, taking O(n) time.

**1.1-4:** The "shortest path" algorithm and "traveling salesman" both involve finding the shortest distance from a "start" to "finish", but in the case of SP, the path contains no cycles and any node is visited at max one time, whereas in TS, that is not true. In SP, some nodes may not be visited, but in TS, all nodes must be visited. SP can be solved in polynomial time, but TS is a NP-complete problem.

**1.1-5:** Some problems where accuracy is required include banking transactions or medical software. Some where an approximate solution will do includes map directions (there may be many routes, but most will do just fine) or elevator controllers (having slight inefficiencies isn't catastrophic).

**1.2-1:** One example of an app that would require algorithms is a meeting scheduler. Given a set number of meeting rooms and a list of meeting times, it would try to determine the optimal way to schedule those meetings so that room utilization is maximized.

**1.2-2:** To determine the breakeven point of the sample runtimes, solve for $8n^2 = 64nlogn$ (approx 43.55). Sample n:

| n   | insertion sort | merge sort |
| --- | -------------- | ---------- |
| 2   | 32             | 128        |
| 4   | 72             | 512        |
| 8   | 512            | 1536       |
| 16  | 2048           | 4096       |
| 32  | 8192           | 10204      |
| 64  | 32768          | 24576      |

**1.2-3:** n = 15

**2.1-1:** Illustration of sorting [26, 31, 41, 41, 58, 59], value being sorted in **bold** and value getting swapped in *italics*.
| Sorted/Sorting               |               Unsorted |
| :--------------------------- | ---------------------: |
| 31                           | **41**, 59, 26, 41, 58 |
| 31, **41**                   |         59, 26, 41, 58 |
| 31, 41, **59**               |             26, 41, 58 |
| 31, 41, 59, **26**           |                 41, 58 |
| 31, 41, **26**, *59*         |                 41, 58 |
| 31, **26**, *41*, 59         |                 41, 58 |
| **26**, *31*, 41, 59         |                 41, 58 |
| 26, 31, 41, 59, **41**       |                     58 |
| 26, 31, 41, **41**, *59*     |                     58 |
| 26, 31, 41, 41, 59, **58**   |                        |
| 26, 31, 41, 41, **58**, *59* |                        |

**2.1-2:** See *insertion_sort.cpp* for insertion sort in non-increasing and non-decreasing order.

**2.1-3**: See *linear_search.cpp* for linear search.

**2.1-4**: See *sum_of_two_binary_numbers.cpp* for adding two n-bit binary ints.

**2.3-1:** Illustration of merge sort on an array:
```
                              [3, 41, 52, 26, 38, 57, 9, 49]
                                   /                   \
                      [3, 41, 52, 26]                 [38, 57, 9, 49]
                      /             \                 /             \
              [3, 41]             [52, 26]        [38, 57]            [9, 49]
             /       \           /       \       /        \          /       \
           [3]      [41]       [52]     [26]   [38]      [57]      [9]       [49]
            \         /          \       /       \        /          \        /
              [3, 41]             [26, 52]        [38, 57]             [9, 49]
                      \           /                        \          / 
                     [3, 26, 41, 52]                     [9, 38, 49, 57]
                                    \                   /
                                 [3, 9, 26, 38, 41, 49, 57]
```
**2.3-2:** See *merge_sort.cpp* for merge sort.

**2.3-3:** TODO

**2.3-4:** The worst-case scenario for insertion sort as a recursive procedure is if the array were in decreasing order to start, e.g. [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]. In that case, every time n is appended to the end of the 0 to n - 1 sequence, it must travel up all the way to the front, causing n - 1 swaps. Because the base case is an array of one element (sorted by definition), we've maximized the amount of work done in every recursive call.

**2.3-5:** See *binary_search.cpp* for binary search.

**2.3-6:** Yes, because we already know that if we're at value n, then 0 to n - 1 is already sorted, so we can binary search it for a number that's greater than the value at n, AND either has no number before it or has a number before it that's less than the value at n, like so:

```
The first 6 numbers are before our current value 7, so we know they've already been sorted.
Do a binary search through that set, for a number that matches the description above.
That would be 9 (> 7, and whose neighbor is 3, and 3 < 7). 7 Can then be inserted between 3 and 9.
[-4, 0, 3, 9, 20, 33 ... **7**, 49, 3, -7, 2]
          ^                 
```

**2.3-7:** We can use $nlogn$ time sorting if the numbers are not already sorted. For the search step, we can use $nlogn$ time to go through the array linearly, and for each element, do a binary search for its corresponding pair. Or better, we can do the search step in O(n) by using two pointers that begin at the ends of the array and slide inwards depending on whether the sum of the currently pointed-at numbers is greater or less than the value we're seeking. Illustrated below:
```
[-7  1  5  8  13  26  33], 31
  ^                    ^       -7 + 33 = 26, 26 < 31, so move left pointer right

[-7  1  5  8  13  26  33]
     ^                 ^       1 + 33 = 34, 34 > 31, so move right pointer left

[-7  1  5  8  13  26  33]
     ^            ^            1 + 26 = 27, 27 < 31, so move left pointer right

[-7  1  5  8  13  26  33]
        ^         ^            5 + 26 = 31, return their indices
```


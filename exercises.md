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


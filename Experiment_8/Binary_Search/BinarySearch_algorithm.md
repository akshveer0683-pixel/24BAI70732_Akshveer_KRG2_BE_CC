BINARY SEARCH ALGORITHM
=======================

Definition:
Binary Search is a search algorithm that finds the position of a target value 
within a SORTED array by repeatedly dividing the search interval in half.

Key Requirement:
- The array MUST be sorted in ascending or descending order.

How it works:
1. Compare the target with the middle element of the array
2. If the middle element equals the target, return its index (SUCCESS)
3. If the middle element is less than the target:
   - Search in the right half (elements greater than middle)
4. If the middle element is greater than the target:
   - Search in the left half (elements smaller than middle)
5. Repeat until element is found or search space is exhausted

Variants:
a) Iterative Binary Search - Uses loops
b) Recursive Binary Search - Uses function recursion

Advantages:
- Extremely fast for large datasets
- Significantly faster than linear search
- Predictable performance

Disadvantages:
- Requires sorted input
- Not suitable for unsorted data without preprocessing
- Slightly more complex than linear search

Conditions:
- Array must be pre-sorted
- Works on contiguous arrays
- Efficient only when random access is available

TIME AND SPACE COMPLEXITY ANALYSIS
===================================

TIME COMPLEXITY:
- Best Case: O(1)
  When the target element is at the middle position on first comparison
  Example: Array [1, 5, 10, 15, 20], target = 10
  Found in 1 comparison

- Average Case: O(log n)
  Typically requires log₂(n) comparisons
  For array of size 1,000,000: ~20 comparisons needed
  For array of size 1,000,000,000: ~30 comparisons needed

- Worst Case: O(log n)
  When element is at one end or not present
  Still requires log₂(n) comparisons maximum
  Example: Array of 16 elements needs max 4 comparisons

Why logarithmic?
- Each iteration eliminates half the remaining elements
- Problem size reduces from n → n/2 → n/4 → n/8 → ... → 1
- Number of divisions: log₂(n)

SPACE COMPLEXITY:
- Iterative Approach: O(1) - Constant space
  Only uses fixed variables (left, right, mid)
  Independent of input size

- Recursive Approach: O(log n) - Linear in logarithmic scale
  Due to recursion call stack
  Maximum recursion depth = log₂(n) levels
  Each level stores function call parameters on stack

Comparison with Linear Search:
- Linear Search: O(n) time, O(1) space
- Binary Search: O(log n) time, O(1) space (iterative)
- Binary Search is superior for large sorted arrays

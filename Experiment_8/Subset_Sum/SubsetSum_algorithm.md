SUBSET SUM ALGORITHM
====================

Problem Definition:
Given an array of integers and a target sum, determine if there exists a 
subset of the array elements whose sum equals the target sum.

This is a Decision Problem (Yes/No answer), not an Optimization Problem.

Related Variant:
Partition Equal Subset Sum - Find if array can be split into two equal sum subsets

Example:
Array: [3, 34, 4, 12, 5, 2]
Target: 9
Solution: YES (subset {4, 5} or {3, 2, 4} sum to 9)

Algorithm Approach: Dynamic Programming

Key Concept:
Use a 2D boolean DP table where:
- dp[i][j] = true if we can achieve sum j using elements from first i elements
- dp[i][j] = false otherwise

Recurrence Relation:
For each element arr[i-1]:
  Option 1: Don't include it → dp[i-1][j]
  Option 2: Include it → dp[i-1][j - arr[i-1]] (if arr[i-1] <= j)
  
  dp[i][j] = dp[i-1][j] OR (arr[i-1] <= j AND dp[i-1][j - arr[i-1]])

Base Cases:
- Sum of 0 is always possible (empty subset) → dp[i][0] = true for all i
- Using 0 elements, only sum 0 is possible → dp[0][j] = false for j > 0

Steps:
1. Create a 2D DP table of size (n+1) × (targetSum+1)
2. Initialize base cases
3. Fill table row by row using recurrence relation
4. Return dp[n][targetSum]

Why DP?
- Overlapping subproblems: Same sums computed multiple times
- Optimal substructure: Larger problems build on smaller ones
- Memoization eliminates redundant calculations

Backtracking (Optional):
After computing if subset exists, backtrack from dp[n][targetSum] to find
which elements form the subset by checking:
- If dp[i-1][j] is true, element i is not included
- Otherwise, element i is included, update j = j - arr[i-1]

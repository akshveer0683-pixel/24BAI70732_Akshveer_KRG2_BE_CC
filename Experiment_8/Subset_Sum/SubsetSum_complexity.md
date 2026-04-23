TIME AND SPACE COMPLEXITY ANALYSIS
===================================

TIME COMPLEXITY: O(n × targetSum)

Where:
- n = number of elements in array
- targetSum = target sum value

Analysis:
- Outer loop: Iterates n times (for each element)
- Inner loop: Iterates targetSum times (for each possible sum)
- Each cell computation: O(1)
- Total: n × targetSum iterations = O(n × targetSum)

Example:
- Array size n = 10, targetSum = 100
  Complexity = 10 × 100 = 1000 operations

- Array size n = 100, targetSum = 1000
  Complexity = 100 × 1000 = 100,000 operations

Important Note:
This is NOT polynomial in the input size because targetSum can be exponentially large
relative to the array size. This makes it a PSEUDO-POLYNOMIAL algorithm.

SPACE COMPLEXITY: O(n × targetSum)

DP Table:
- 2D array of size (n+1) × (targetSum+1)
- Each boolean value: 1 byte
- Total: (n+1) × (targetSum+1) bytes

Space Breakdown:
- DP table: O(n × targetSum)
- Input array: O(n)
- Variables (i, j, etc.): O(1)
- Total: O(n × targetSum)

Space Optimization:
Can be reduced to O(targetSum) using 1D DP array
Instead of 2D table dp[i][j], use 1D array dp[j]
Iterate backward through targetSum to avoid overwriting needed values

Optimized Space Code Pattern:
```
vector<bool> dp(targetSum + 1, false);
dp[0] = true;
for (int i = 0; i < n; i++) {
    for (int j = targetSum; j >= arr[i]; j--) {
        dp[j] = dp[j] || dp[j - arr[i]];
    }
}
```

Comparison:
Original Space: O(n × targetSum)
Optimized Space: O(targetSum)
Time: O(n × targetSum) in both cases

When to optimize:
- If targetSum is very large
- If n is small compared to targetSum
- Memory is a constraint

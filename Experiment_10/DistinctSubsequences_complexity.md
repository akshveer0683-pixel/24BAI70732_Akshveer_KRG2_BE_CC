TIME AND SPACE COMPLEXITY ANALYSIS
===================================

Time Complexity:
- We process each character of `s` and for each character we iterate over `t`.
- Total time complexity: O(n * m), where `n = |s|` and `m = |t|`.

Space Complexity:
- The solution uses a 1D DP array of size `m + 1`.
- Space complexity: O(m).

Notes:
- This optimized DP uses constant additional space besides the DP array.
- If the count becomes very large, use a larger integer type or modular arithmetic as required.

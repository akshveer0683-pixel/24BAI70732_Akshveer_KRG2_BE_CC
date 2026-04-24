DISTINCT SUBSEQUENCES ALGORITHM
===============================

Problem:
Given two strings `s` and `t`, return the number of distinct subsequences of `s` that equal `t`.

Approach:
Use dynamic programming to count how many ways each prefix of `t` can be formed from prefixes of `s`.

Steps:
1. Let `n = s.length()` and `m = t.length()`.
2. Create a DP array `dp[0..m]` where `dp[j]` is the number of distinct subsequences of the processed prefix of `s` that equals `t[0..j-1]`.
3. Initialize `dp[0] = 1` because the empty string is a subsequence of any string.
4. Iterate through each character of `s` as `s[i-1]`.
5. For each `i`, update `dp[j]` from `j = m` down to `1`:
   - If `s[i-1] == t[j-1]`, then add `dp[j-1]` to `dp[j]`.
6. After processing all characters, `dp[m]` holds the final count.

Why it works:
- When characters match, each subsequence that forms `t[0..j-2]` can extend to form `t[0..j-1]`.
- Reverse iteration prevents overwriting values needed for the current row.
- The DP effectively counts all valid subsequence selection paths.

Example:
For `s = "rabbbit"` and `t = "rabbit"`, there are 3 distinct subsequences.

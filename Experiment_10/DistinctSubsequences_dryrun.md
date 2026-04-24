DRY RUN
=======

Input:
S = rabbbit
T = rabbit

Step 1: Initialize
- s = "rabbbit"
- t = "rabbit"
- n = 7, m = 6
- dp = [1, 0, 0, 0, 0, 0, 0]

Step 2: Process s[0] = 'r'
- j = 6..1, only match at j = 1
- dp[1] += dp[0] => dp[1] = 1
- dp = [1, 1, 0, 0, 0, 0, 0]

Step 3: Process s[1] = 'a'
- match at j = 2 => dp[2] += dp[1] = 1
- dp = [1, 1, 1, 0, 0, 0, 0]

Step 4: Process s[2] = 'b'
- match at j = 3 => dp[3] += dp[2] = 1
- dp = [1, 1, 1, 1, 0, 0, 0]

Step 5: Process s[3] = 'b'
- match at j = 3 => dp[3] += dp[2] = 2
- match at j = 4 => dp[4] += dp[3] (previous value 1) => dp[4] = 1
- dp = [1, 1, 1, 2, 1, 0, 0]

Step 6: Process s[4] = 'b'
- match at j = 3 => dp[3] += dp[2] = 3
- match at j = 4 => dp[4] += dp[3] (previous value 2) = 3
- dp = [1, 1, 1, 3, 3, 0, 0]

Step 7: Process s[5] = 'i'
- match at j = 5 => dp[5] += dp[4] = 3
- dp = [1, 1, 1, 3, 3, 3, 0]

Step 8: Process s[6] = 't'
- match at j = 6 => dp[6] += dp[5] = 3
- dp = [1, 1, 1, 3, 3, 3, 3]

Output:
3

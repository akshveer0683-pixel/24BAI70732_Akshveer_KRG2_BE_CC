DRY RUN EXAMPLE
===============

Test Case:
Array: [3, 34, 4, 12, 5, 2]
Target Sum: 9

Initial DP Table (showing relevant portion):
dp[i][j] where i = 0 to 6, j = 0 to 9

Initialize:
- dp[i][0] = true for all i (sum 0 is always possible)
- All other entries = false

       j=0  j=1  j=2  j=3  j=4  j=5  j=6  j=7  j=8  j=9
i=0    T    F    F    F    F    F    F    F    F    F
i=1    T    F    F    T    F    F    F    F    F    F
i=2    T    F    F    T    F    F    F    T    T    F
i=3    T    F    F    T    T    F    F    T    T    T
i=4    T    F    F    T    T    T    F    T    T    T
i=5    T    F    T    T    T    T    T    T    T    T
i=6    T    T    T    T    T    T    T    T    T    T

STEP-BY-STEP FILLING:

Element 1: arr[0] = 3, i=1
j=3: dp[1][3] = dp[0][3] OR dp[0][3-3] = F OR dp[0][0] = F OR T = TRUE
j=4-9: All false (3 > j or no valid sums)

Element 2: arr[1] = 34, i=2
No changes in our target range (34 > 9)

Element 3: arr[2] = 4, i=3
j=4: dp[3][4] = dp[2][4] OR dp[2][4-4] = F OR dp[2][0] = F OR T = TRUE
j=7: dp[3][7] = dp[2][7] OR dp[2][7-4] = T OR dp[2][3] = T OR T = TRUE
j=8: dp[3][8] = dp[2][8] OR dp[2][8-4] = T OR dp[2][4] = T OR F = TRUE
j=9: dp[3][9] = dp[2][9] OR dp[2][9-4] = F OR dp[2][5] = F OR F = TRUE

Element 4: arr[3] = 12, i=4
12 > 9, no updates in our range

Element 5: arr[4] = 5, i=5
j=5: dp[5][5] = dp[4][5] OR dp[4][0] = F OR T = TRUE
j=8: dp[5][8] = dp[4][8] OR dp[4][3] = T OR T = TRUE
j=9: dp[5][9] = dp[4][9] OR dp[4][4] = T OR T = TRUE

Element 6: arr[5] = 2, i=6
j=2: dp[6][2] = dp[5][2] OR dp[5][0] = F OR T = TRUE
j=5: dp[6][5] = dp[5][5] OR dp[5][3] = T OR T = TRUE
j=9: dp[6][9] = dp[5][9] OR dp[5][7] = T OR T = TRUE

FINAL ANSWER:
dp[6][9] = TRUE
Result: Subset with sum 9 EXISTS

BACKTRACKING TO FIND SUBSET:
Start at dp[6][9] = TRUE
i=6, j=9, arr[5]=2

Check dp[5][9] = TRUE → Element 2 not included, i=5
Check dp[4][9] = TRUE → Element 12 not included, i=4
Check dp[3][9] = TRUE → Element 5 not included, i=3
Check dp[2][9] = FALSE → Element 4 IS included!
  j = 9 - 4 = 5, i = 2
Check dp[1][5] = FALSE → Element 34 IS included? No, skip
Check dp[0][5] = FALSE → Backtrack continues
  
Actually simpler subset: {4, 5} = 9
Another subset: {3, 2, 4} = 9

Possible Answers (multiple subsets may exist):
- {4, 5}
- {3, 2, 4}

Both sum to 9, proving the answer is YES

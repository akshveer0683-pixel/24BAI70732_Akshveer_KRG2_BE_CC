DRY RUN EXAMPLE
===============

Scenario:
Array: [2, 5, 8, 12, 16, 23, 38, 45, 56, 67]
Target: 23
Array size (n) = 10

ITERATION 1:
left = 0, right = 9
mid = 0 + (9-0)/2 = 4
arr[4] = 16
Is 16 == 23? NO
Is 16 < 23? YES → Search right half
left = 5

ITERATION 2:
left = 5, right = 9
mid = 5 + (9-5)/2 = 7
arr[7] = 45
Is 45 == 23? NO
Is 45 < 23? NO → Search left half
right = 6

ITERATION 3:
left = 5, right = 6
mid = 5 + (6-5)/2 = 5
arr[5] = 23
Is 23 == 23? YES → FOUND!
Return index = 5

RESULT: Element found at index 5
Success! Total comparisons = 3

Comparison with Linear Search:
Linear search would need 6 comparisons (linear through positions 0-5)
Binary search needed only 3 comparisons (log₂(10) ≈ 3.32)

---

FAILED SEARCH EXAMPLE:
Array: [2, 5, 8, 12, 16, 23, 38, 45, 56, 67]
Target: 30

ITERATION 1:
left = 0, right = 9
mid = 4, arr[4] = 16
16 < 30 → left = 5

ITERATION 2:
left = 5, right = 9
mid = 7, arr[7] = 45
45 > 30 → right = 6

ITERATION 3:
left = 5, right = 6
mid = 5, arr[5] = 23
23 < 30 → left = 6

ITERATION 4:
left = 6, right = 6
mid = 6, arr[6] = 38
38 > 30 → right = 5

LOOP ENDS: left > right (6 > 5)
Return -1 (Element NOT found)

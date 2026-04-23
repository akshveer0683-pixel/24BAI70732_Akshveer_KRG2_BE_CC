TIME AND SPACE COMPLEXITY ANALYSIS
===================================

TIME COMPLEXITY: O(n!)

Detailed Analysis:
- Starting city is fixed (city 0)
- Remaining (n-1) cities can be permuted
- Number of permutations: (n-1)!
- For each permutation: O(n) to calculate tour cost
- Total: O(n × (n-1)!) = O(n!)

Growth:
n=4:   3! = 6 tours
n=5:   4! = 24 tours
n=10:  9! = 362,880 tours
n=15:  14! = 87,178,291,200 tours
n=20:  19! ≈ 1.2 × 10¹⁷ tours

Practical Time Limits (at 10⁸ operations/second):
n=10:  ~0.004 seconds ✓
n=12:  ~0.5 seconds ✓
n=13:  ~6 seconds ✓
n=14:  ~90 seconds ✓
n=15:  ~20 minutes ✗
n=20:  ~4 million years ✗

With Pruning:
Best Case: O(n!) still, but many branches cut
Average Case: Often much better than O(n!) in practice
Effectiveness depends on distance distribution

SPACE COMPLEXITY: O(n)

Space Breakdown:
- path array: O(n) - stores current tour
- visited array: O(n) - tracks visited cities
- Recursion stack: O(n) - maximum depth is n
- Input distance matrix: O(n²) - not counted as algorithm space

Total Algorithm Space: O(n) + O(n²) = O(n²) if counting input
Algorithm-only space: O(n) excluding input

Memory Usage:
n=10:   ~100-200 bytes
n=15:   ~225-450 bytes
n=20:   ~400-800 bytes
n=100:  ~10-20 KB

Space is NOT a bottleneck; TIME is the main issue.

Comparison with Other Approaches:

Approach          Time Complexity    Space Complexity    Guarantee Optimal
------            ---------------    ----------------    -----------------
Brute Force       O(n!)              O(n)                YES
Dynamic Prog      O(n² × 2ⁿ)         O(n × 2ⁿ)           YES
Nearest Neighbor  O(n²)              O(n)                NO
Genetic Algo      Variable           O(population)       NO
Simulated Anneal  Variable           O(n)                NO

Why Brute Force is Impractical:
- Factorial growth is the worst possible
- Even with pruning, n=15 is typically the limit
- For large n, other approaches are necessary

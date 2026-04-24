TRAVELING SALESMAN PROBLEM (TSP) - BRUTE FORCE
================================================

Problem Definition:
Given n cities and distances between every pair of cities, find the shortest 
possible route that visits each city exactly once and returns to the starting city.

NP-Hard Problem:
TSP is one of the most famous NP-hard problems in computer science.
No known polynomial-time solution exists.

Problem Characteristics:
- Must visit every city exactly once
- Must return to starting city
- Objective: Minimize total distance/cost
- Directed/Undirected: Can be both
- Symmetric/Asymmetric: Can be both

Example:
Cities: {0, 1, 2, 3}
Start: City 0

Possible tours (one direction):
- 0 → 1 → 2 → 3 → 0
- 0 → 1 → 3 → 2 → 0
- 0 → 2 → 1 → 3 → 0
- 0 → 2 → 3 → 1 → 0
- 0 → 3 → 1 → 2 → 0
- 0 → 3 → 2 → 1 → 0

Total permutations for n cities: (n-1)!/2 for undirected, (n-1)! for directed

BRUTE FORCE APPROACH (Exhaustive Search)

Algorithm:
1. Start from city 0
2. Generate all possible permutations of remaining cities
3. For each permutation:
   a. Calculate total distance
   b. Include return distance to starting city
   c. Track minimum cost and corresponding path
4. Backtrack to explore other permutations
5. Return the tour with minimum cost

Backtracking Optimization:
- Prune branches where current cost exceeds minimum found so far
- Avoid exploring tours that cannot be optimal

Key Features:
- GUARANTEES optimal solution
- Explores all possible tours
- Simple to implement
- Inefficient for large inputs (n > 12)

Pseudocode:
```
function TSP(cities, distMatrix, currentPath, visited, currentCost):
    if all cities visited:
        if cost to return to start + currentCost < minCost:
            update minCost and bestPath
        return
    
    for each unvisited city:
        if currentCost + distance to city < minCost:  // Pruning
            mark city as visited
            add city to path
            TSP(cities, distMatrix, path, visited, currentCost + distance)
            remove city from path
            unmark city as visited
```

When to use Brute Force TSP:
- Small number of cities (≤ 12-15)
- Need guaranteed optimal solution
- Exact algorithm is required
- Time is not a constraint

For Larger Problems:
- Use Heuristics: Nearest Neighbor, Greedy
- Use Metaheuristics: Simulated Annealing, Genetic Algorithm
- Use Approximation: Christofides Algorithm
- Use Dynamic Programming: Held-Karp (O(n² × 2ⁿ))

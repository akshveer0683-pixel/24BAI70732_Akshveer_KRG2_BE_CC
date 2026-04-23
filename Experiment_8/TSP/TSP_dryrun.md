DRY RUN EXAMPLE
===============

Problem:
4 cities (0, 1, 2, 3)
Starting city: 0

Distance Matrix:
      0   1   2   3
  0   0  10  15  20
  1  10   0  35  25
  2  15  35   0  30
  3  20  25  30   0

Initial Setup:
- Start at city 0
- Visit cities 1, 2, 3 in all possible orders
- Total permutations: 3! = 6 tours

All Possible Tours and Costs:

Tour 1: 0 → 1 → 2 → 3 → 0
Cost: dist[0][1] + dist[1][2] + dist[2][3] + dist[3][0]
     = 10 + 35 + 30 + 20 = 95

Tour 2: 0 → 1 → 3 → 2 → 0
Cost: dist[0][1] + dist[1][3] + dist[3][2] + dist[2][0]
     = 10 + 25 + 30 + 15 = 80

Tour 3: 0 → 2 → 1 → 3 → 0
Cost: dist[0][2] + dist[2][1] + dist[1][3] + dist[3][0]
     = 15 + 35 + 25 + 20 = 95

Tour 4: 0 → 2 → 3 → 1 → 0
Cost: dist[0][2] + dist[2][3] + dist[3][1] + dist[1][0]
     = 15 + 30 + 25 + 10 = 80

Tour 5: 0 → 3 → 1 → 2 → 0
Cost: dist[0][3] + dist[3][1] + dist[1][2] + dist[2][0]
     = 20 + 25 + 35 + 15 = 95

Tour 6: 0 → 3 → 2 → 1 → 0
Cost: dist[0][3] + dist[3][2] + dist[2][1] + dist[1][0]
     = 20 + 30 + 35 + 10 = 95

COMPARISON:
Tour 1: Cost = 95
Tour 2: Cost = 80 ← OPTIMAL
Tour 3: Cost = 95
Tour 4: Cost = 80 ← OPTIMAL (same distance, reverse direction)
Tour 5: Cost = 95
Tour 6: Cost = 95

OPTIMAL TOURS (Multiple optimal solutions exist):
- 0 → 1 → 3 → 2 → 0 with cost 80
- 0 → 2 → 3 → 1 → 0 with cost 80 (reverse of above)

Best Path Found: [0, 1, 3, 2] or [0, 2, 3, 1]
Minimum Cost: 80

ALGORITHM EXECUTION TRACE:

Initial: path=[0], visited=[T,F,F,F], cost=0

Level 1 (Try city 1):
  path=[0,1], visited=[T,T,F,F], cost=10
  
  Level 2 (Try city 2):
    path=[0,1,2], visited=[T,T,T,F], cost=45
    
    Level 3 (Try city 3):
      path=[0,1,2,3], visited=[T,T,T,T], cost=75
      Total cost = 75 + dist[3][0] = 75 + 20 = 95
      minCost = 95, bestPath = [0,1,2,3]
    
  Level 2 (Try city 3):
    path=[0,1,3], visited=[T,T,F,T], cost=35
    
    Level 3 (Try city 2):
      path=[0,1,3,2], visited=[T,T,T,T], cost=65
      Total cost = 65 + dist[2][0] = 65 + 15 = 80
      minCost = 80, bestPath = [0,1,3,2] ← UPDATE

[Continues for other paths...]

Level 1 (Try city 2):
  Similar exploration...

Level 1 (Try city 3):
  Similar exploration...

FINAL RESULT:
Optimal Tour: 0 → 1 → 3 → 2 → 0
Minimum Cost: 80

Why this is optimal:
- Direct paths are preferred (0→1: 10, 1→3: 25)
- Avoids expensive paths (1→2: 35)
- Returns efficiently (2→0: 15)

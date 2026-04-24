The algorithm used in this program is the Bellman Ford Algorithm to find the shortest path from point A to B in K+1 iterations where A and B are any points of a connected graph.
<br><br>
**Algorithm**
1. Initialise dist[src] = 0 because distance of source node to source node is always zero.<br>
2. Repeat for k+1 times<br>
- Copy dist to temp<br>
  - For each flight from u to v with cost wt<br>
    - If dist[u] + wt < temp[v]<br>
      - Update temp[v] with dist[u] + wt<br>
- Assign dist=temp<br>
3. Return dist[dst] if destination is reachable <br>
If not, return -1

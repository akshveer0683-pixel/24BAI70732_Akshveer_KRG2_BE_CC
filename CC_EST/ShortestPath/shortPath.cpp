class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges, int src) {
        
        // Build adjacency list
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Distance array
        vector<int> dist(V, INT_MAX);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        // BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (dist[it] == INT_MAX) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }

        // Replace unreachable with -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};
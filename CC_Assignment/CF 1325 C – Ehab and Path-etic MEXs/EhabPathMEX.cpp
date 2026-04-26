#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> edges(n-1);
    vector<int> degree(n+1, 0);

    for(int i = 0; i < n-1; i++) {
        cin >> edges[i].first >> edges[i].second;
        degree[edges[i].first]++;
        degree[edges[i].second]++;
    }

    vector<int> ans(n-1, -1);

    int node = -1;

    // Find node with degree >= 3
    for(int i = 1; i <= n; i++) {
        if(degree[i] >= 3) {
            node = i;
            break;
        }
    }

    int label = 0;

    // Assign 0,1,2 to edges connected to that node
    if(node != -1) {
        for(int i = 0; i < n-1; i++) {
            if(edges[i].first == node || edges[i].second == node) {
                if(label < 3) {
                    ans[i] = label++;
                }
            }
        }
    }

    // Assign remaining labels
    for(int i = 0; i < n-1; i++) {
        if(ans[i] == -1) {
            ans[i] = label++;
        }
    }

    // Output
    for(int x : ans) {
        cout << x << endl;
    }

    return 0;
}
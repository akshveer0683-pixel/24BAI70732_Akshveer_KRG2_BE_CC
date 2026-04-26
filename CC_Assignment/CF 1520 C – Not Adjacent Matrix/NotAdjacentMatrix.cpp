#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        if(n == 2) {
            cout << -1 << "\n";
            continue;
        }

        vector<int> v;

        // first odd numbers
        for(int i = 1; i <= n*n; i += 2) {
            v.push_back(i);
        }

        // then even numbers
        for(int i = 2; i <= n*n; i += 2) {
            v.push_back(i);
        }

        int idx = 0;

        // fill matrix row-wise
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << v[idx++] << " ";
            }
            cout << "\n";
        }
    }
}
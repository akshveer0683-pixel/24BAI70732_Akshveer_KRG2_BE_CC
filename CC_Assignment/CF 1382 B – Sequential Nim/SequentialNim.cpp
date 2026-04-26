#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int k = 0;

        // count leading 1s
        for(int i = 0; i < n; i++) {
            if(a[i] == 1) k++;
            else break;
        }

        if(k == n) {
            // all ones
            if(n % 2) cout << "First\n";
            else cout << "Second\n";
        } else {
            if(k % 2 == 0) cout << "First\n";
            else cout << "Second\n";
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int totalOnes = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) totalOnes++;
    }

    // Convert array: 0 -> +1, 1 -> -1
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) b[i] = 1;
        else b[i] = -1;
    }

    // Kadane's Algorithm
    int maxSum = b[0], currSum = b[0];

    for(int i = 1; i < n; i++) {
        currSum = max(b[i], currSum + b[i]);
        maxSum = max(maxSum, currSum);
    }

    // If all 1s
    if(maxSum <= 0) {
        cout << totalOnes - 1 << endl;
    } else {
        cout << totalOnes + maxSum << endl;
    }

    return 0;
}
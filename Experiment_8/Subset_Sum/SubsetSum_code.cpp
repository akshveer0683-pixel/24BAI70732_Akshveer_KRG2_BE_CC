#include <iostream>
#include <vector>
using namespace std;

// Subset Sum - Verification Version (Decision Problem)
// Determines if a subset with given sum exists
bool subsetSumVerification(vector<int>& arr, int targetSum) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));
    
    // Base case: sum of 0 is always possible (empty subset)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    
    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= targetSum; j++) {
            // Option 1: Don't include arr[i-1]
            dp[i][j] = dp[i-1][j];
            
            // Option 2: Include arr[i-1] (if possible)
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i][j] || dp[i-1][j - arr[i-1]];
            }
        }
    }
    
    return dp[n][targetSum];
}

// Subset Sum - Finding the Subset
void printSubsetSum(vector<int>& arr, int targetSum) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));
    
    // Initialize base case
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    
    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= targetSum; j++) {
            dp[i][j] = dp[i-1][j];
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i][j] || dp[i-1][j - arr[i-1]];
            }
        }
    }
    
    // Backtrack to find the actual subset
    if (!dp[n][targetSum]) {
        cout << "No subset found!\n";
        return;
    }
    
    vector<int> subset;
    int i = n, j = targetSum;
    
    while (i > 0 && j > 0) {
        // If value comes from top, element is not included
        if (dp[i-1][j]) {
            i--;
        } else {
            // Element is included
            subset.push_back(arr[i-1]);
            j -= arr[i-1];
            i--;
        }
    }
    
    cout << "Subset found: ";
    for (int x : subset) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int targetSum = 9;
    
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n\nTarget Sum: " << targetSum << "\n";
    
    // Verification
    bool exists = subsetSumVerification(arr, targetSum);
    cout << "\nSubset exists: " << (exists ? "YES" : "NO") << "\n";
    
    // Find and print the subset
    if (exists) {
        printSubsetSum(arr, targetSum);
    }
    
    // Test case 2
    cout << "\n--- Test Case 2 ---\n";
    vector<int> arr2 = {1, 2, 3, 7};
    int targetSum2 = 6;
    
    cout << "Array: ";
    for (int x : arr2) cout << x << " ";
    cout << "\n\nTarget Sum: " << targetSum2 << "\n";
    
    bool exists2 = subsetSumVerification(arr2, targetSum2);
    cout << "\nSubset exists: " << (exists2 ? "YES" : "NO") << "\n";
    
    if (exists2) {
        printSubsetSum(arr2, targetSum2);
    }
    
    return 0;
}

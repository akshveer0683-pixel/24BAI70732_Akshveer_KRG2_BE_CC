#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;
    vector<int> a(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Sliding window to find maximum consecutive books
    int maxBooks = 0;
    int currentSum = 0;
    int left = 0;

    for(int right = 0; right < n; right++)
    {
        currentSum += a[right];

        // Shrink window from left if sum exceeds t
        while(currentSum > t && left <= right)
        {
            currentSum -= a[left];
            left++;
        }

        // Update maximum books (right - left + 1 is current window size)
        maxBooks = max(maxBooks, right - left + 1);
    }

    cout << maxBooks << endl;
    return 0;
}
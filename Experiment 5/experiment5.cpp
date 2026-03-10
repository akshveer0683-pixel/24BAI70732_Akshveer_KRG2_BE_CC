class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        long long e = 1e9 + 7;
        
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));
        
        dp[0][0]=1;
        
        for(int i=1; i<=n; i++) 
        {
            for(int j=0; j<=target; j++) 
            {
                dp[i][j]=dp[i-1][j];

                if(arr[i-1]<=j) 
                {
                    dp[i][j]=(dp[i][j] + dp[i-1][j-arr[i-1]])%e;
                }
            }
        }
        
        return dp[n][target];
    }
};

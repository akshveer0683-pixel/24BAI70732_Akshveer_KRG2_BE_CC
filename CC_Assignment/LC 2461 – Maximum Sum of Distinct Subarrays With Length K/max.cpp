class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        long long sum = 0;
        long long maxSum = 0;
        
        int left = 0;

        for(int right = 0; right < nums.size(); right++) {
            // expand window
            sum += nums[right];
            freq[nums[right]]++;

            // shrink if size > k
            if(right - left + 1 > k) {
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                sum -= nums[left];
                left++;
            }

            // check valid window
            if(right - left + 1 == k && freq.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};
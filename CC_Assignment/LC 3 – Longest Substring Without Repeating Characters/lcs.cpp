class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int n=s.length();
        int maxL=0, l=0;
        for(int r=0; r<n; r++)
        {
            if(last[s[r]] >= l)
                l=last[s[r]] + 1;
            
            last[s[r]] = r;
            maxL=max(maxL, r - l + 1);
        }
        return maxL;
    }
};
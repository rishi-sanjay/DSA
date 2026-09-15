class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), count(n, 1);
        count[0] = 1;
        int county = 0, mx = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
            
                } else if (nums[i] > nums[j] && (dp[j] + 1 == dp[i])) {
                    count[i] += count[j];
                }
            }
            mx=max(mx,dp[i]);
        }
        int i = 0;
        for (int val : dp) {
            if (val == mx)
                county += count[i];
            i += 1;
        }
        return county;
    }
};
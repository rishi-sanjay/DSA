class Solution {
public:
    int call(vector<int>& nums, int idx, vector<vector<int>>& dp, int j) {
        if (idx == nums.size())
            return 0;
        if (dp[idx][j + 1] != -1)
            return dp[idx][j+1];
        int np = call(nums, idx + 1, dp, j);

        int p = 0;
        if (j == -1 || nums[idx] > nums[j])
            p = 1 + call(nums, idx + 1, dp,  idx);
        return dp[idx][j + 1] = max(p, np);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return call(nums, 0, dp, -1);
    }
};
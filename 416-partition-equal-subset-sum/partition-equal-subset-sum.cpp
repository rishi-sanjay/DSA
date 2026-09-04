class Solution {
public:
    bool call(int tar, vector<int>& nums, int idx, vector<vector<int>>& dp) {
        if (tar == 0)
            return true;
        if (dp[idx][tar] != -1)
            return dp[idx][tar];
        if (idx == 0)
            return nums[0] == tar;
        bool np = call(tar, nums, idx - 1, dp);
        bool pi = false;
        if (tar - nums[idx] > 0)
            pi = call(tar - nums[idx], nums, idx - 1, dp);
        return dp[idx][tar] = pi || np;
    }
    bool canPartition(vector<int>& nums) {

        int i = 0, sum = 0;
        for (int val : nums) {
            sum += val;
            i += 1;
        }
        if (sum % 2)
            return false;
        vector<vector<int>> dp(i + 1, vector<int>(sum + 1, -1));
        return call(sum / 2, nums, i - 1, dp);
    }
};
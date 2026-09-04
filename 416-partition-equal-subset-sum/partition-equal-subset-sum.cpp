class Solution {
public:
    bool call(int tar, int sum, vector<int>& nums, int idx, vector<vector<int>>&dp) {
        if (sum == tar)
            return true;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        if (idx == 0 || tar > sum)
            return false;
        bool np = call(tar, sum, nums, idx - 1,dp);
        bool pi = false;
        if (tar + nums[idx] <= sum - nums[idx])
            pi = call(tar + nums[idx], sum - nums[idx], nums, idx - 1,dp);
        return dp[idx][sum]=pi || np;
    }
    bool canPartition(vector<int>& nums) {
        
        int i = 0, sum = 0;
        for (int val : nums){
            sum += val;
            i+=1;
        }
        vector<vector<int>>dp(i+1,vector<int>(sum+1,-1));
        return call(0, sum, nums, i-1,dp);
    }
};
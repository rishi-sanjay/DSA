class Solution {
public:
    int call(vector<int>& coins, int k, int idx, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (coins[0] == 0 and k == 0)
                return 2;
            if (coins[0] ==k || k==0)
                return 1;
            return 0;
        }
        if (dp[idx][k] != -1)
            return dp[idx][k];
        int p = 0, np = 0;
        np = call(coins, k, idx - 1, dp);
        if (k >= coins[idx]) {
            p = call(coins, k - coins[idx], idx - 1, dp);
        }
        return dp[idx][k] = p + np;
    }
    int findTargetSumWays(vector<int>& coins, int amount) {
        int n = coins.size();
        int sum = 0;
        for (int val : coins)
            sum += val;
        if (sum-amount<0 || (sum - amount) % 2 == 1)
            return 0;
        int tar = (sum - amount) / 2;
        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
        return call(coins, tar, n - 1, dp);
    }
};
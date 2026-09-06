class Solution {
public:
    int call(vector<int>& coins, int k, int idx, vector<vector<int>>& dp) {
        if (k == 0)
            return 1;
        if (idx == 0) {
            if (coins[0] <= k && k % coins[0] == 0)
                return 1;
            return 0;
        }
        if (dp[idx][k] != -1)
            return dp[idx][k];
        int p = 0;
        int np = call(coins, k, idx - 1, dp);
        if (k >= coins[idx] ) {
          p = call(coins, k - coins[idx], idx, dp);
        }
        dp[idx][k] = p + np;
        return dp[idx][k];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return call(coins, amount, n - 1, dp);
    }
};
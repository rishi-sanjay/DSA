class Solution {
public:
    int call(vector<int>& coins, int k, int idx, vector<vector<int>>& dp) {
        if (k == 0)
            return 0;
        if (idx == 0) {
            if (coins[0] <= k && k % coins[0] == 0)
                return k / coins[0];
            return INT_MAX;
        }
        if (dp[idx][k] != -1)
            return dp[idx][k];
        int p = INT_MAX;
        int np = call(coins, k, idx - 1, dp);
        if (k - coins[idx] >= 0) {
            int temp = call(coins, k - coins[idx], idx, dp);
            if (temp != INT_MAX)
                p = 1 + temp;
        }
        return dp[idx][k] = min(p, np);
    }
    int coinChange(vector<int>& coins, int amount) {

        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int co = call(coins, amount, n - 1, dp);
        if (co == INT_MAX)
            return -1;
        return co;
    }
};
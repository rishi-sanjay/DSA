class Solution {
public:
    int call(vector<int>& s, int idx, int buy, vector<vector<int>>& dp) {
        if (idx >= s.size())
            return 0;
        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        int pr = 0;
        if (buy) { // buy
            int x = 0, y = 0;
                x = -s[idx] + call(s, idx + 1, 0, dp); // buy
            y = 0 + call(s, idx + 1, 1, dp);           // skip
            pr = max(x, y);
        } else
            pr = max(s[idx] + call(s, idx + 2, 1, dp), // sold
                     call(s, idx + 1, 0, dp));         // hold
        return dp[idx][buy] = pr;
    }
    int maxProfit(vector<int>& pri) {
        int n = pri.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return call(pri, 0, 1, dp);
    }
};
class Solution {
public:
    int call(vector<int>& s, int idx, int buy, vector<vector<int>>& dp) {
        if (idx == s.size() || buy < 0)
            return 0;
        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        int pr = 0;
        if (buy % 2) // buy
            pr = max(-s[idx] + call(s, idx + 1, buy - 1, dp),
                     0 + call(s, idx + 1, buy, dp));
        else
            pr = max(s[idx] + call(s, idx + 1, buy - 1, dp),
                     0 + call(s, idx + 1, buy, dp));
        return dp[idx][buy] = pr;
    }
    int maxProfit(vector<int>& pri) {
        int mx = 0, n = pri.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return call(pri, 0, 3, dp);
    }
};
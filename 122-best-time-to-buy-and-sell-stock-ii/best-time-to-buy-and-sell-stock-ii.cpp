class Solution {
public:
    int call(vector<int>& s, int idx, int mx, vector<vector<int>>& dp) {
        if (idx == s.size())
            return 0;
        if (dp[idx][mx] != -1)
            return dp[idx][mx];
        int pr = 0;
        if (mx) // buy
            pr = max(-s[idx] + call(s, idx + 1, 0, dp),
                     0 + call(s, idx + 1, 1, dp));
        else
            pr = max(s[idx] + call(s, idx + 1, 1, dp),
                     0 + call(s, idx + 1, 0, dp));
        return dp[idx][mx] = pr;
    }
    int maxProfit(vector<int>& pri) {
        int mx = 0, n = pri.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return call(pri, 0,1, dp);
    }
};
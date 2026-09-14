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
    int Profit(vector<int>& pri,int k) {
        int n = pri.size();
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        return call(pri, 0, 2*k-1, dp);
    }

    int maxProfit(int k, vector<int>& prices) {
        return Profit(prices,k);
    }
};
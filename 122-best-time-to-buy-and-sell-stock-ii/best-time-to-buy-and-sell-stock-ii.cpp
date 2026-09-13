class Solution {
public:
    int maxProfit(vector<int>& s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2,0));
        dp[n-1][0] = s[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            for (int i = 0; i < 2; i++) {
                if (i != 1)//sell 
                    dp[j][i] = max(s[j] + dp[j + 1][1], dp[j + 1][0]);
                else
                    dp[j][i] = max(-s[j] + dp[j + 1][0], dp[j + 1][1]);
            }
        }
        return dp[0][1];
    }
};
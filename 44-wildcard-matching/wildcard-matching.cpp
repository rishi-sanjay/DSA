class Solution {
public:
    bool call(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 && j < 0)
            return true;
        if (j < 0)
            return false;
        if (i < 0 && j >= 0) {
            for (int y = j; y >= 0; y--) {
                if (t[y] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (t[j] == '*')
            return dp[i][j] =
                       call(s, t, i - 1, j, dp) || call(s, t, i, j - 1, dp);
        if (s[i] == t[j] || t[j] == '?')
            return dp[i][j] = call(s, t, i - 1, j - 1, dp);
        return dp[i][j] = false;
    }
    int longestCommonSubsequence(string& text1, string& text2, bool& ans) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return call(text1, text2, m - 1, n - 1, dp);
    }

    bool isMatch(string x, string p) {
        bool ans = 0;
        bool call = longestCommonSubsequence(x, p, ans);
        if (ans)
            return true;
        return call;
    }
};
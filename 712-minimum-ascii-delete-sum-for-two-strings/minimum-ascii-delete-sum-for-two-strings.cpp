class Solution {
public:
    int call(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (i < 0){
            int sum=0;
            while(j>=0)
               sum+=t[j--];
            return sum;
        }
        else if (j < 0){
                 int sum=0;
            while(i>=0)
               sum+=s[i--];
            return sum;
        }
        if (dp[i][j] != INT_MAX)
            return dp[i][j];
        if (s[i] == t[j])
            return dp[i][j] = call(s, t, i - 1, j - 1, dp);
        return dp[i][j] = min(s[i] + call(s, t, i - 1, j, dp),
                              t[j] + call(s, t, i, j - 1, dp));
    }
    int longestCommonSubsequence(string& text1, string& text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        return call(text1, text2, m - 1, n - 1, dp);
    }
    int minimumDeleteSum(string s1, string s2) {
        return longestCommonSubsequence(s1, s2);
    }
};
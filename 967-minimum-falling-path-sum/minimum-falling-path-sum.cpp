class Solution {
public:
    int call(vector<vector<int>>& mat, int r, int c, int n, int m,
             vector<vector<int>>& dp) {
        if (r == n - 1)
            return mat[r][c];
        if (dp[r][c] != INT_MAX)
            return dp[r][c];
        int nr = r + 1;
        int l = INT_MAX;
        int ri = l, d = l;
        if (c - 1 >= 0)
            l = call(mat, nr, c - 1, n, m, dp);
        d = call(mat, nr, c, n, m, dp);
        if (c + 1 <= n - 1)
            ri = call(mat, nr, c + 1, n, m, dp);
        return dp[r][c] = mat[r][c] + min({l, d, ri});
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int ans = INT_MAX;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < m; i++) {
            ans = min(ans, call(mat, 0, i, n, m, dp));
        }
        return ans;
    }
};
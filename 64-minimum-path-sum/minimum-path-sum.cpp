class Solution {
public:
    int call(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {
        if (m == 0 && n == 0)
            return grid[m][n];
        if (dp[m][n] != -1)
            return dp[m][n];
        int left = INT_MAX, up = INT_MAX;
        // left
        if (n > 0)
            left = call(grid, m, n - 1, dp);
        if (m > 0)
            up = call(grid, m - 1, n, dp);

        return dp[m][n] = grid[m][n] + min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return call(grid, m - 1, n - 1, dp);
    }
};
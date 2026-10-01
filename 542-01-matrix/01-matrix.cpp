class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int vis[n][m];
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        int dis = 0;
        vector<int> drow = {-1, 0, 0, 1};
        vector<int> dcol = {0, -1, 1, 0};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int tm = q.front().second;
            ans[r][c] = tm;
            q.pop();
            dis = max(dis, tm);
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    vis[nrow][ncol] == 0) {
                    q.push({{nrow, ncol}, dis + 1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return ans;
    }
};
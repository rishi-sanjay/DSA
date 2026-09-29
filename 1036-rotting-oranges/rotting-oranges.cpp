class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int ans = 0, cntfresh = 0;
        queue<pair<pair<int, int>, int>> q;
        int vis[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                } else {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1)
                    cntfresh++;
            }
        }
        int cnt=0;
        vector<int> drow = {-1, 0, 0, 1};
        vector<int> dcol = {0, -1, 1, 0};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int tm = q.front().second;
            q.pop();
            ans = max(ans, tm);
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, ans + 1});
                    vis[nrow][ncol] = 1;
                    cnt++;
                }
            }
        }
        if(cnt!=cntfresh) return -1;
        return ans;
    }
};
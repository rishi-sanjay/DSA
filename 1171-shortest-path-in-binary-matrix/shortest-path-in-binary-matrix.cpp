class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(n, -1));
        int ans = 0;
        if (grid[0][0] == 0)
            q.push({{0, 0}, 1});
        vis[0][0] = 1;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int st = q.front().second;
            q.pop();
            ans = max(ans, st);
            if ((r == n - 1) && (c == r))
                return ans;
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    int nr = r + i;
                    int nc = c + j;
                    if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                        vis[nr][nc] == -1 && grid[nr][nc] == 0) {
                        vis[nr][nc] = 1;
                        q.push({{nr, nc}, st + 1});
                    }
                }
            }
        }
        return -1;
    }
};
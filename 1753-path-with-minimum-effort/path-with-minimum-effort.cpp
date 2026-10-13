class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& he) {
        int n = he.size();
        int m = he[0].size();
        vector<vector<int>> vis(n, vector<int>(m, INT_MAX));
        vis[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<int> dr={0, -1, 1, 0};
        vector<int> dc = {-1, 0, 0, 1};
        pq.push({0, {0, 0}});
        int ans = INT_MAX;
        while (!pq.empty()) {
            auto it = pq.top();
            int st = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            if (r == n - 1 && c == m - 1){
                vis[r][c]=min(vis[r][c],st);
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int nr = dr[i] + r;
                int nc = dc[i] + c;
                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    int diff = abs(he[nr][nc] - he[r][c]);
                    diff = max(diff, st);
                    if(vis[nr][nc]>diff){
                        pq.push({diff,{nr,nc}});
                        vis[nr][nc]=diff;
                    }
                }
            }
        }
        return vis[n-1][m-1];
    }
};
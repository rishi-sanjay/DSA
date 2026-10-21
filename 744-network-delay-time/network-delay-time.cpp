class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, 1e8);
        dist[k] = 0;
        for (int i = 0; i < n - 1; i++) {

            for (auto e : times) {
                int u = e[0];
                int v = e[1];
                int wt = e[2];

                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        int ans =INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (k == i)
                continue;
            if (dist[i] == 1e8)
                return -1;

            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
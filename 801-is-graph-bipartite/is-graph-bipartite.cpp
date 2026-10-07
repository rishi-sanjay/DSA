class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v, -1);
        for (int i = 0; i < v; i++) {
            if (vis[i] != -1)
                continue;
            queue<int> q;
            q.push(i);
            vis[0] = 0;
            while (!q.empty()) {
                int node = q.front();
                int color = vis[node];
                q.pop();
                for (int val : graph[node]) {
                    if (vis[val] == -1) {
                        vis[val] = 1 ^ color;
                        q.push(val);
                    } else if (vis[val] != (1 ^ color))
                        return false;
                }
            }
        }
        return true;
    }
};
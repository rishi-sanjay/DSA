class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
       
        pq.push({0, 0});
        int mod = 1e9 + 7;
        vector<int> way(n, 0);
        vector<long long> dis(n, LLONG_MAX);
        way[0] = 1;
        dis[0]=0;
        while (!pq.empty()) {
            auto it = pq.top();
            long long step = it.first;
            int node = it.second;
            pq.pop();

            for (auto val : adj[node]) {
                int x = val.first;
                long long st = val.second;
                if (step + st < dis[x]) {
                    dis[x] = step + st;
                    pq.push({dis[x], x});
                    way[x] = way[node];
                } else if (step + st == dis[x]) {
                    way[x] = (way[x] + way[node]) % mod;
                }
            }
        }
        return way[n - 1];
    }
};
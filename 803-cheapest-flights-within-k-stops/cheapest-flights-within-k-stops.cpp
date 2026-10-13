class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
        queue<pair<int, pair<int, int>>> pq;
        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            int src = it[0];
            int dist = it[1];
            int cost = it[2];
            adj[src].push_back({dist, cost});
        }
        pq.push({0, {src, 0}});
        while (!pq.empty()) {
            auto it = pq.front();
            int step = it.first;
            int node = it.second.first;
            int diss = it.second.second;
            pq.pop();
            if (step > k)
                continue;

            for (auto it : adj[node]) {
                int no = it.first;
                int we = it.second;

                if (we + diss < dis[no] && step <= k) {
                    dis[no] = we + diss;
                    pq.push({step + 1, {no, dis[no]}});
                }
            }
        }
        if (dis[dst] == INT_MAX)
            return -1;
        return dis[dst];
    }
};
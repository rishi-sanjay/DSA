#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        
        
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        
        
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        
    
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        int minReachable = n;
        int bestCity = -1;
        
        
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            
            if (reachableCount <= minReachable) {
                minReachable = reachableCount;
                bestCity = i;
            }
        }
        
        return bestCity;
    }
};
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int num = graph.size();
        vector<int> adj[num];
        vector<int> in(num, 0);

        for (int i = 0; i < num; i++) {
            in[i]=graph[i].size();
            for (int val : graph[i]) {
                adj[val].push_back(i);
             
            }
        }
        queue<int> q;
        for (int i = 0; i < num; i++) {
            if (in[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty()) {
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for (int p : adj[x]) {
                in[p]--;
                if (in[p] == 0)
                    q.push(p);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
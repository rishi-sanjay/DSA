class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& prer) {
    vector<int> adj[num];
    int n=prer.size();
    for(int i=0;i<n;i++){
             int fir=prer[i][1];
             int sec=prer[i][0];
             adj[fir].push_back(sec);
        }
        vector<int> in(num, 0);
        for (int i = 0; i < num; i++) {
            for (int val : adj[i]) {
                in[val]++;
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
        return ans.size() == num;
    }
};
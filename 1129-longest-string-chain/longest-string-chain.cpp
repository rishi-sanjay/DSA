class Solution {
public:
    bool call(int i, int j, vector<string>& w) {
        string p = w[i], q = w[j];
        if (p.size() != q.size() + 1)
            return false;
        int x = 0, y = 0;
        while (x < p.size()) {
            if (y < q.size() && p[x] == q[y]) {
                y += 1;
                x += 1;
            } else
                x += 1;
        }
        if (y==q.size())
            return true;
        return false;
    }
    static bool comp(string& ss, string& tt) { return ss.size() < tt.size(); }
    int longestStrChain(vector<string>& w) {
        sort(w.begin(), w.end(), comp);
        int n = w.size();
        int mx = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (call(i, j, w) == true)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            mx = max(dp[i], mx);
        }
        return mx;
    }
};
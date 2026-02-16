class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;
        unordered_map<char, int> m;
        int idx = 0;
        for (char x : s) {
            if (m.find(x) == m.end()) {
                q.push(idx);
                m[x]++;
            } else {
                m[x]++;
                if (!q.empty() && s[q.front()] == x) {
                    while (!q.empty() && m[s[q.front()]] != 1)
                        q.pop();
                }
            }
            idx++;
        }
        if (q.empty())
            return -1;
        return q.front();
    }
};
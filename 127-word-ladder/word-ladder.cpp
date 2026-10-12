class Solution {
public:
    int ladderLength(string be, string end, vector<string>& word) {

        queue<pair<string, int>> q;
        unordered_set<string> s(word.begin(), word.end());
        q.push({be, 1});
        s.erase(be);
        while (!q.empty()) {
            string wo = q.front().first;
            int step = q.front().second;
            q.pop();
            if (wo == end)
                return step;
            for (int i = 0; i < wo.size(); i++) {
                char op = wo[i];
                for (char st = 'a'; st <= 'z'; st++) {
                    wo[i] = st;

                    if (s.find(wo) != s.end()) {
                        s.erase(wo);
                        q.push({wo, step + 1});
                    }
                }
                wo[i] = op;
            }
        }

        return 0;
    }
};
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int r = 0, l = 0, mxlen = 0;
        unordered_map<int, int> m;
        while (r < fruits.size()) {
            m[fruits[r]] += 1;
            if (m.size() > 2) {
                m[fruits[l]] -= 1;
                if (m[fruits[l]] == 0)
                    m.erase(fruits[l]);
                l += 1;
            }
            if (m.size() <= 2)
                mxlen = max(mxlen, r - l + 1);
            r += 1;
        }
        return mxlen;
    }
};
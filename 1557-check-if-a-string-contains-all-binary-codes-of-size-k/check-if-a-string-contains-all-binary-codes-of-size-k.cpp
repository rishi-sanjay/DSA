class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<int> se;
        int sz = s.size();
        if (sz < k)
            return false;
        int p = 1, ans = 0;
        for (int i = k - 1; i >= 0; i--) {
            if (s[i] == '1')
                ans = ans + p;
            p *= 2;
        }
        
        se.insert(ans);
        for (int i = k; i < sz; i++) {
            ans = ans * 2;
            if (s[i - k] == '1')
                ans = ans - p;
            if (s[i] == '1')
                ans += 1;
            if (se.find(ans) == se.end())
                se.insert(ans);
        }
        if (k == 1)
            return se.size() == 2;
        int range = 1 << k;
        return se.size() == range;
    }
};
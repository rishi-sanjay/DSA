class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int j = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) != m.end())
                if (m[s[i]] + 1 > j)
                    j = m[s[i]] + 1;
            m[s[i]] = i;
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
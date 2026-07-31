class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, maxlen = 0;
        vector<int>arr(256,-1);
        for (int r = 0; r < s.length(); r++) {
            if (arr[s[r]] != -1 && (l <= arr[s[r]])) {
                l = arr[s[r]] + 1;
            }
            arr[s[r]] = r;
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};
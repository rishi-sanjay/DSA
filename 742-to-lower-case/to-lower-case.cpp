class Solution {
public:
    string toLowerCase(string s) {
        string ans = "";
        for (char x : s) {
            ans += tolower(x);
        }
        return ans;
    }
};
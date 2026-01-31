class Solution {
public:
    void boss(vector<string> &ans, int n, string temp, int last, int idx) {
        if (idx == n) {
            ans.push_back(temp);
            return;
        }
        if (last != 0) {
            boss(ans, n, temp + '0', 0, idx + 1);
        }
        boss(ans, n, temp + '1', 1, idx + 1);
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        boss(ans, n, "", 1, 0);
        return ans;
    }
};
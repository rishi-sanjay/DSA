class Solution {
public:
    bool isvalid(string s, int st, int end) {
        while (st <= end) {
            if (s[st++] != s[end--])
                return false;
        }
        return true;
    }
    void boss(string s, vector<string>& temp, vector<vector<string>>& ans,
              int idx) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (isvalid(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                boss(s, temp, ans, i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        boss(s, temp, ans, 0);
        return ans;
    }
};
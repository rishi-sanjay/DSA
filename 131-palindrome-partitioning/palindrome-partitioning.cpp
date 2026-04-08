class Solution {
public:
    bool ispal(string& s, int st, int end) {
        while (st < end) {
            if (s[st++] != s[end--])
                return false;
        }
        return true;
    }
    void boss(vector<vector<string>>& ans, string& s, int idx,
              vector<string>& temp) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (ispal(s, idx, i) == true) {
                temp.push_back(s.substr(idx, i - idx + 1));
                boss(ans, s, i + 1, temp);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        boss(ans, s, 0, temp);
        return ans;
    }
};
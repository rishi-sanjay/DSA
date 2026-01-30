class Solution {
public:
    void boss(string temp, vector<string>& ans, int n, int st, int end) {
        if (temp.size() == 2 * n) {
            ans.push_back(temp);
            return;
        }
        if (st < n) {
            boss(temp + '(', ans, n, st + 1, end);
        }
        if (st > end) {
            boss(temp + ')', ans, n, st, end + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        boss("", ans, n, 0, 0);
        return ans;
    }
};
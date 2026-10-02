class Solution {
public:
    void generate(vector<string>& ans, string temp, int L, int R, int n) {
        if (temp.size() == 2 * n) {
            ans.push_back(temp);
        }
        if (L < n) {
            L += 1;
            generate(ans, temp + '(', L, R, n);
            L -= 1;
        }
        if (R < L) {
            R += 1;
            generate(ans, temp + ')', L, R, n);
            R -= 1;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans, "", 0, 0, n);
        return ans;
    }
};
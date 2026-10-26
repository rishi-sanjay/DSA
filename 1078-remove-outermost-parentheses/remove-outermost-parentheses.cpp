class Solution {
public:
    string removeOuterParentheses(string s) {
        int op = 0;
        string ans = "";
        for (char x : s) {
            if (x == '(') {
                op++;
                if (op > 1)
                    ans += x;
            } else {
                op--;
                if (op != 0)
                    ans += x;
            }
        }
        return ans;
    }
};
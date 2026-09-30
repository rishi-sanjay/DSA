class Solution {
public:
    int minAddToMakeValid(string s) {
        int op = 0;
        int ans = 0;
        for (char val : s) {
            if (val == '(')
                op++;
            else {
                if (op == 0)
                    ans += 1;
                else
                    op--;
            }
        }
        return ans + op;
    }
};
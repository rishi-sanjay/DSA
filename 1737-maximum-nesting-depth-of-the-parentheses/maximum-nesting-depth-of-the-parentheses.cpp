class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, count = 0;
        for (char x : s) {
            if (x == '(')
                ans += 1;
            else if (x == ')') {
                count = max(ans, count);
                ans--;
            }
        }
        return count;
    }
};
class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int count = 0;
        for (char x : s) {
            if (x == '(') {
                count++;
                ans = max(count, ans);
            } else if (x==')')
                count--;
        }
        return ans;
    }
};
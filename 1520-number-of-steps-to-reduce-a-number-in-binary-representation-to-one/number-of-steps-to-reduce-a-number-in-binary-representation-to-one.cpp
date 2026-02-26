class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        int carr = 0;
        for (int i = s.size() - 1; i > 0; i--) {
            int b = (s[i] - '0') + carr;
            if (b == 1) {
                ans += 2;
                carr = 1;
            } else {
                ans += 1;
            }
        }
        return carr + ans;
    }
};
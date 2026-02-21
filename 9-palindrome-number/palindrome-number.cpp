class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        long long ans = 0;
        long long p = x;
        while (p > 0) {
            int di = p % 10;
            ans = ans * 10 + di;
            p /= 10;
        }
        if (x == (int)ans)
            return true;
        return false;
    }
};
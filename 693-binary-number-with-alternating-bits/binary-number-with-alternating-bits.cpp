class Solution {
public:
    bool hasAlternatingBits(int n) {
        int la = 2;
        while (n > 0) {
            int p = n % 2;
            if (p == la)
                return false;
            la=p;
            n /= 2;
        }
        return true;
    }
};
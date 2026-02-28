class Solution {
public:
    bool isHappy(int n) {
        long long k = n, ans;
        set<int> s;
        while (true) {
            if (s.find(k) != s.end())
                return false;
            s.insert(k);
            if (k == 1)
                break;
            if (k < 4)
                return false;
            ans = 0;
            while (k > 0) {
                int p = k % 10;
                ans = ans + (p * p);
                k /= 10;
            }
            k = ans;
        }
        return true;
    }
};
class Solution {
public:
    bool boss(int x) {
        if (x < 2)
            return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for (int j = L; j <= R; j++) {
            if (boss(__builtin_popcount(j)))
                ans += 1;
        }
        return ans;
    }
};
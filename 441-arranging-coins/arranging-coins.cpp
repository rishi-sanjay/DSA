class Solution {
public:
    int arrangeCoins(int n) {
        long long x = n, k = 1;
        while (x >= k * (k + 1) >> 1)
            k += 1;
        return k - 1;
    }
};
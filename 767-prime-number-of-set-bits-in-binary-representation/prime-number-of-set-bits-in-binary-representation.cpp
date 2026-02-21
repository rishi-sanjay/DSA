class Solution {
public:
    int countBits(int n) {
        int c = 0;
        while (n) {
            c += (n & 1);
            n >>= 1;
        }
        return c;
    }

    bool isPrime(int x) {
        if (x < 2)
            return false;
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
                return false;
        return true;
    }

    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for (int i = L; i <= R; i++) {
            int bits = countBits(i);
            if (isPrime(bits))
                ans++;
        }
        return ans;
    }
};
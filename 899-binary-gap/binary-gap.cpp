class Solution {
public:
    int binaryGap(int n) {

        int lsb = -1;
        int rem = 2;
        int ans = 0;
        int c = -1;
        while (n > 0) {
            int b = n & 1;
            c += 1;
            if (b == 1) {
                if (rem == 1 && lsb != -1)
                    ans = max(1, ans);
                else if (rem == 0 && lsb != -1)
                    ans = max(ans, c - lsb);
                lsb = c;
            }
            rem = b;
            n /= 2;
        }
        return ans;
    }
};
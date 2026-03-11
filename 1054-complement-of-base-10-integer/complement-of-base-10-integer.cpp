class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int ans = 0;
        int p = n;
        while (p > 0) {
            ans = (ans << 1) | 1;
            p /= 2;
        }
        return ans ^ n;
        ;
    }
};
class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        int len = 0;
        const int z =1e9 + 7;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0)
                len+=1;
            ans = ((ans << len) | i) % z;
        }
        return (int)ans;
    }
};
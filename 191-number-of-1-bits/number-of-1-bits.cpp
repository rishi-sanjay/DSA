class Solution {
public:
    int boss(int n) {
        if (n == 0 || n == 1)
            return n;
        if (n & 1)
            return 1 + boss(n / 2);
        else
            return boss(n / 2);
    }
    int hammingWeight(int n) { 
        return boss(n); 
        }
};
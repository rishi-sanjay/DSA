class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        int ldi = num;
        while (ldi > 0) {
            if ((num % (ldi % 10)) == 0)
                ans += 1;
            ldi /= 10;
        }
        return ans;
    }
};
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;
        int st = 1;
        int end = x / 2;
        while (st <= end) {
            int mid = (st + end) >> 1;
            long long sq = (long long)mid * mid;
            if (sq == x)
                return mid;
            else if (sq > x)
                end = mid - 1;
            else
                st = mid + 1;
        }
        return end;
    }
};
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0, r = 0, l = 0, zero = 0;
        while (r < nums.size()) {
            if (nums[r] == 0) 
                zero += 1;
                if (zero > k) {
                    if (nums[l] == 0)
                        zero--;
                    l += 1;
                }
            if (zero <= k)
                maxlen = max(maxlen, r - l + 1);
            r += 1;
        }
        return maxlen;
    }
};
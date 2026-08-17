class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0, ans = 0, r = 0, count = 0;
        int sz = nums.size();
        while (r < sz) {
            xr ^= nums[r];
            if (xr != 0) {
                ans = r + 1;
                if (nums[r] > 0)
                    count++;
            }
            r += 1;
        }
        if (count == 0)
            return 0;
        if (xr != 0)
            return ans;
        else
            return sz - 1;
    }
};
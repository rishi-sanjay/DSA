class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;
        int p = end;
        vector<int> ans(end + 1, 0);
        while (st <= end) {
            int x = nums[st] * nums[st];
            int y = nums[end] * nums[end];
            if (x > y) {
                ans[p] = x;
                st += 1;
            } else {
                ans[p] = y;
                end--;
            }
            p--;
        }
        return ans;
    }
};
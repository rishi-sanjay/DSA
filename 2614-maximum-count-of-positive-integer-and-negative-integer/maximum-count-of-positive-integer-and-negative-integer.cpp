class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int ans = 0;
        int sz = nums.size();
        int st = 0, end = sz - 1;
        while (st <= end) {
            int mid = (st + end) >> 1;
            if (nums[mid] < 0)
                st = mid + 1;
            else
                end = mid - 1;
        }
        ans = st;
        if (ans > sz / 2)
            return ans;
        end = sz - 1;
        while (st <= end) {
            int mid = (st + end) >> 1;
            if (nums[mid] <= 0)
                st = mid + 1;
            else
                end = mid - 1;
        }
        ans = max(ans, sz - st);
        return ans;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suff(n);
        pre[0] = nums[0];
        suff[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] * nums[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] * nums[i];
        }
        for (int i = 0; i < n; i++) {
            if (i == 0)
                nums[i] = suff[1];
            else if (i == n - 1)
                nums[i] = pre[n - 2];
            else
                nums[i] = suff[i + 1] * pre[i - 1];
        }
        return nums;
    }
};
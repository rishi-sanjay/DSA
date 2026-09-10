class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        int suff = nums[n - 1];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] * nums[i];
        }
        pre[n-1]=pre[n-2];
        for (int i = n-2; i >=0; i--) {
            if (i == 0)
                pre[i] = suff;
            else
                pre[i] = suff* pre[i - 1];
            suff*=nums[i];
        }
        return pre;
    }
};
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sz = nums.size();
        for (int i = 1; i < sz; i++) {
            nums[i] += nums[i - 1];
        }
        int left = 0;
        int right = 0;
        for (int i = 0; i < sz; i++) {
            if (i != 0)
                left = nums[i - 1];

            if (i == sz - 1)
                right = 0;
            else
                right = nums[sz - 1] - nums[i];
            if (left == right)
                return i;
        }
        return -1;
    }
};
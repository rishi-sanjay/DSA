class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, m = 0, h = nums.size() - 1 ;
         while (l <= h) {
            if (nums[l] == 0) {
                swap(nums[l++], nums[m++]);
            } else if (nums[l] == 1) {
                l++;
            } else {
                swap(nums[l], nums[h--]);
            }
        }
    }
};
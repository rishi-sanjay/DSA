class Solution {
public:
    void boss(vector<int>& nums, int st, int end) {
        if (st < end) {
            int mid = st + (end - st) / 2;
            boss(nums, st, mid);
            boss(nums, mid + 1, end);

            vector<int> temp;
            int i = st;
            int j = mid + 1;
            while (i <= mid && j <= end) {
                if (nums[i] > nums[j]) {
                    temp.push_back(nums[j]);
                    j++;
                } else {
                    temp.push_back(nums[i]);
                    i++;
                }
            }
            while (i <= mid) {
                temp.push_back(nums[i]);
                i++;
            }
            while (j <= end) {
                temp.push_back(nums[j]);
                j++;
            }
            for (int k = 0; k < temp.size(); k++) {
                nums[k + st] = temp[k];
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        boss(nums, 0, nums.size() - 1);
        return nums;
    }
};
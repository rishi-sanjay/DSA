class Solution {
public:
    int search(vector<int>& nums, int k) {
        int st = 0, end = nums.size() - 1;
        while (st <= end) {
            int mid = (end + st) / 2;
            if (nums[mid] == k)
                return mid;
            if (nums[st] <= nums[mid]) {
                if (nums[st] <= k && nums[mid] >= k)
                    end = mid - 1;
                else
                    st = mid + 1;
            } else {
                if (nums[mid] <= k && nums[end] >= k)
                    st = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};
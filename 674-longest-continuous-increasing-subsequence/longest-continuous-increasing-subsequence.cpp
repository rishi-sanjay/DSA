class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 1;
        int back = nums[0];
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= back)
                count = 1;
            else if (nums[i] > back)
                count += 1;    
            ans = max(count, ans);
            back=nums[i];
        }
        return ans;
    }
};
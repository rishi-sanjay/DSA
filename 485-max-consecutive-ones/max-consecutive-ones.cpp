class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, count = 0;
        for (int val : nums) {
            count += val;
            ans = max(count, ans);
            if (val == 0)
                count = 0;
        }
        return ans;
    }
};
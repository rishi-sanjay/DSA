class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), tr(n);
        int last = 0, mx = 1;
        for (int i = 0; i < n; i++) {
            tr[i] = i;
            for (int j = 0; j < i; j++) {
                if (((nums[i] % nums[j] == 0) || (nums[j] % nums[i] == 0)) &&
                    dp[j] + 1 >= dp[i]) {
                    tr[i] = j;
                    dp[i] = 1 + dp[j];
                }
            }
            if (mx < dp[i]) {
                last = i;
                mx = dp[i];
            }
        }
        vector<int> ans;
        ans.push_back(nums[last]);
        while (tr[last] != last) {
            last = tr[last];
            ans.push_back(nums[last]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
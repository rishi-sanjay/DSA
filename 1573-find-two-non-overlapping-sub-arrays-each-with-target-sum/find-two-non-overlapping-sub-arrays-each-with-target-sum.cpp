class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int tar) {
        int r = 0, l = 0;
        int n = arr.size();
        int ans = INT_MAX, min_len = INT_MAX;
        vector<int> dp(n, INT_MAX);
        int sum = 0;
        while (r < n) {
            sum += arr[r];
            while (sum > tar) {
                sum -= arr[l++];
            }
            if (sum == tar) {
                int len = r - l + 1;
                if (l > 0 && dp[l - 1] != INT_MAX)
                    ans = min(ans, len + dp[l - 1]);
                min_len = min(len, min_len);
            }
            dp[r] = min_len;
            r += 1;
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};
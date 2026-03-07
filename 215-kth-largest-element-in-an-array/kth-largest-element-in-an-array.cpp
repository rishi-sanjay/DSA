class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (int val : nums) {
            q.push(val);
        }
        int ans = q.top();
        while (k != 0) {
            ans = q.top();
            q.pop();
            k--;
        }
        return ans;
    }
};
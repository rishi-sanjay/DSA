class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int sz = nums.size();
        for (int i = 2 * sz - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % sz]) {
                st.pop();
            }
            int p=nums[i%sz];
            if (i < sz) {
                if (st.empty()) {
                    nums[i] = -1;
                } else
                    nums[i] = st.top();
            }
            st.push(p);
        }
        return nums;
    }
};
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> temp;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (temp.empty() != true && temp.top() <= nums2[i]) {
                temp.pop();
            }
            if (!temp.empty())
                m[nums2[i]] = temp.top();
            else
                m[nums2[i]] = -1;
            temp.push(nums2[i]);
        }
        vector<int> ans;
        for (int val : nums1) {
            ans.push_back(m[val]);
        }
        return ans;
    }
};
class Solution {
public:
    string multiply(string nums1, string nums2) {
        if(nums1=="0" || nums2=="0") return "0";
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans(n + m, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                ans[i + j + 1] += (nums1[i] - '0') * (nums2[j] - '0');
                ans[i + j] += ans[i + j + 1] / 10;
                ans[i + j + 1] %= 10;
            }
        }
        int i = 0;
        while (ans[i] == 0)
            i++;
        string res = "";
        while (i < ans.size())
            res += to_string(ans[i++]);
        return res;
    }
};
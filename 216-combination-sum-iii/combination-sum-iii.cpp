class Solution {
public:
    void boss(vector<int>& temp, vector<vector<int>>& ans, int k, int n,
             int idx) {
        //rishi
        if (n == 0 && temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        if (n < 0)
            return;
        for (int i = idx; i < 10; i++) {
            temp.push_back(i);
            boss(temp, ans, k, n-i , i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        boss(temp, ans, k, n, 1);
        return ans;
    }
};
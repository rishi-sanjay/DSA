class Solution {
    void boss(vector<int>& can, int tar, vector<vector<int>>& ans, int idx,
              vector<int>& temp) {
        if (tar == 0) {
            ans.push_back(temp);
            return;
        }
        if (0 > tar || idx >= can.size())
            return;
        tar -= can[idx];
        temp.push_back(can[idx]);
        boss(can, tar, ans, idx, temp);
        temp.pop_back();
        tar += can[idx];
        boss(can, tar, ans, idx + 1, temp);
        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
        vector<vector<int>> ans;
        vector<int> temp;
        boss(can, tar, ans, 0, temp);
        return ans;
    }
};
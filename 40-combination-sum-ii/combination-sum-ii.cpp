class Solution {
public:
    void boss(vector<int>& can, int tar, vector<vector<int>>& ans,
              vector<int>& temp, int idx, int sum, int sz) {
        if (sum == tar) {
            ans.push_back(temp);
            return;
        }
        if (idx == sz || sum > tar) {
            return;
        }
        sum += can[idx];
        temp.push_back(can[idx]);
        boss(can, tar, ans, temp, idx + 1, sum, sz);
        sum -= can[idx];
        temp.pop_back();
        int p = idx + 1;
        while (p < sz && can[p-1] == can[p]) {
            p++;
        }
        boss(can, tar, ans, temp, p, sum, sz);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
        sort(can.begin(), can.end());
        vector<int> temp;
        vector<vector<int>> ans;
        int sz = can.size();
        boss(can, tar, ans, temp, 0, 0, sz);
        return ans;
    }
};
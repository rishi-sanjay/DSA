class Solution {
public:
    void boss(vector<vector<int>>& ans, int row) {
        for (int i = 0; i < row; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    temp.push_back(1);
                else {
                    int p = ans[i - 1][j - 1] + ans[i - 1][j];
                    temp.push_back(p);
                }
            }
            ans.push_back(temp);
        }
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        boss(ans, numRows);
        return ans;
    }
};
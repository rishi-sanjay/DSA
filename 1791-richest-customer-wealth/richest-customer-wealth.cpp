class Solution {
public:
    int boss(vector<vector<int>>& accounts, int i) {
        int sum = 0;
        for (int j = 0; j < accounts[i].size(); j++) {
            sum += accounts[i][j];
        }
        return sum;
    }
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (int i = 0; i < accounts.size(); i++) {
            ans = max(ans, boss(accounts, i));
        }
        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2,0));
        int sell = s[n - 1],buy=0;
        for (int j = n - 2; j >= 0; j--) {
            for (int i = 0; i < 2; i++) {
                if (i != 1)//sell 
                    sell = max(s[j] + buy, sell);
                else
                    buy = max(-s[j] + sell, buy);
            }
        }
        return buy;
    }
};
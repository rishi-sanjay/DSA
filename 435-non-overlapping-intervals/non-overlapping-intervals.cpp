class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });
        int ans = 0, last = inter[0][1];
        for (int i = 1; i < inter.size(); i++) {
            if (inter[i][0] < last)
                ans += 1;
            else
                last = inter[i][1];
        }
        return ans;
    }
};
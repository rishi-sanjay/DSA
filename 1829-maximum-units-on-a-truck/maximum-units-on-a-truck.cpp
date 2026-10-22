class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int truck) {
        sort(box.begin(), box.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });
        int k = 0, ans = 0;
        for (auto e : box) {
            if (e[0] <= truck) {
                truck -= e[0];
                ans += (e[0] * e[1]);
            } else {
                ans = ans + (truck * e[1]);
                break;
            }
        }
        return ans;
    }
};
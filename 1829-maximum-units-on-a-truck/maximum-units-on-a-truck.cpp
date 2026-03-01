class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int trucksize) {
        sort(box.begin(), box.end(),
             [](auto& a, auto& b) { return a[1] > b[1]; });
        int ans = 0;
        int i = 0;
        int k=trucksize;
        while (i < box.size() && k > 0) {
            if (k >= box[i][0]) {
                ans += (box[i][0] * box[i][1]);
                k -= box[i][0];
            } else {
                ans += k * box[i][1];
                k = 0;
            }
            i++;
        }
        return ans;
    }
};
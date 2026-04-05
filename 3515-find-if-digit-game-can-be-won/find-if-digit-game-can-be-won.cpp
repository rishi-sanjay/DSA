class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single = 0;
        int dou = 0;
        for (int val : nums) {
            if (val < 10)
                single += val;
            else if (val < 100)
                dou += val;
        }
        if (single > dou || dou > single)
            return true;
        return false;
    }
};
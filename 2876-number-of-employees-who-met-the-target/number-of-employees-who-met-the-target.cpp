class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;
        for (int val : hours)
            if (val >= target)
                ans += 1;

        return ans;
    }
};
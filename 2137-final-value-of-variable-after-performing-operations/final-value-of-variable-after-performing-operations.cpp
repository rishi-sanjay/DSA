class Solution {
public:
    int finalValueAfterOperations(vector<string>& oper) {
        int ans = 0;
        for (string x : oper) {
            if (x == "++X" || x == "X++")
                ans += 1;
            else
                ans -= 1;
        }
        return ans;
    }
};
class Solution {
public:
    void boss(string& di, vector<string>& ans, string& temp, int idx) {

        if (temp.size() == di.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < di.size(); i++) {
            int x = di[i] - '0';
            char name = 'a' + (x - 2) * 3;
            int p = i + 1;
            if (x <= 7) {
                for (int j = 0; j < 3; j++) {

                    boss(di, ans, temp += name + j, p);
                    temp.pop_back();
                }
            }
            if (x == 7) {
                boss(di, ans, temp += name + 3, p);
                temp.pop_back();
            }
            if (x >= 8) {
                for (int j = 1; j < 4; j++) {
                    boss(di, ans, temp += name + j, p);
                    temp.pop_back();
                }
            }
            if (x == 9) {
                boss(di, ans, temp += name + 4, p);
                temp.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string di) {
        string temp = "";
        vector<string> ans;
        boss(di, ans, temp, 0);
        return ans;
    }
};
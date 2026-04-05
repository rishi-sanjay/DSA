class Solution {
public:
    bool boss(string x) {
        int st = 0, end = x.size() - 1;
        while (st < end) {
            if (x[st++] != x[end--])
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int i = 0;
        string ans = "";
        while (i < words.size()) {
            if (boss(words[i]) == true) {
                ans = words[i];
                break;
            }

            i += 1;
        }
        return ans;
    }
};
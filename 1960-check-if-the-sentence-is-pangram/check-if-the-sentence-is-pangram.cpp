class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> st(26, false);
        for (char x : sentence) {
            st[x - 'a'] = true;
        }
        for (int i = 0; i < 26; i++) {
            if (st[i] != true)
                return false;
        }
        return true;
    }
};
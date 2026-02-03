class Solution {
public:
    int boss(vector<vector<char>>& mi, string& s, int i, int j, int idx, int m,
             int n, bool x, bool y) {
        if (idx == s.size()) {
            return idx;
        }
        char temp=mi[i][j];
        mi[i][j]='#';

        int re=0;
        if (i < m - 1 && s[idx] == mi[i + 1][j]) {       // down
            re=max(re, boss(mi, s, i + 1, j, idx + 1, m, n, true, true));
        }
        if (j < (n - 1) && s[idx] == mi[i][j + 1] && y == true) { // right
            re=max(re, boss(mi, s, i, j + 1, idx + 1, m, n, false, true));
        }
        if (j > 0 && s[idx] == mi[i][j - 1] && x == true) {
            re=max(re, boss(mi, s, i, j - 1, idx + 1, m, n, true, false)); // left
        }
        if (i > 0 && s[idx] == mi[i - 1][j]) {                     // up
            re=max(re, boss(mi, s, i - 1, j, idx + 1, m, n, true, true));
        }
        mi[i][j]=temp;
        return re;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = 0;
                if (word[idx] == board[i][j]) {
                    int c = boss(board, word, i, j, idx + 1, m, n, true, true);
                    if (c == word.size()) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
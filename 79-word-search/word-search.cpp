class Solution {
public:
    bool boss(vector<vector<char>>& mi, string& s, int i, int j, int idx, int m,
              int n) {
        if (idx == s.size()) {
            return true;
        }
        char temp = mi[i][j];
        mi[i][j] = '#';
        bool x=0, y=0, z=0, w=0;
        if (i != m - 1 && s[idx] == mi[i + 1][j]) { // down
            x = boss(mi, s, i + 1, j, idx + 1, m, n);
        }
        if (j != (n - 1) && s[idx] == mi[i][j + 1]) { // right
            y = boss(mi, s, i, j + 1, idx + 1, m, n);
        }
        if (j != 0 && s[idx] == mi[i][j - 1]) {
            w = boss(mi, s, i, j - 1, idx + 1, m, n); // left
        }
        if (i != 0 && s[idx] == mi[i - 1][j]) { // up
            z = boss(mi, s, i - 1, j, idx + 1, m, n);
        }
        mi[i][j] = temp;
        return x || y || z || w;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = 0;
                if (word[idx] == board[i][j]) {
                    bool c = boss(board, word, i, j, idx + 1, m, n);
                    if (c == true) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
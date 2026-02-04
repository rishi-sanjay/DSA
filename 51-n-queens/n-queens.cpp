class Solution {
public:
    bool col(int i, int j, int n, vector<vector<char>>& m) {
        for (int k = 0; k < i; k++) {
            if (m[k][j] == 'Q')
                return false;
        }
        return true;
    }
    bool dia(int i, int j, int n, vector<vector<char>>& m) {
        int r = i;
        int s = j;
        if (j != 0) {
            while (s != 0 and r>0) {
                if (m[r-1][s-1] == 'Q') {
                    return false;
                }
                r -= 1;
                s -= 1;
            }
        }
        r = i;
        s = j;
        if (j != (n - 1)) {
            while (s != (n - 1) and r>0) {
                if (m[r - 1][s + 1] == 'Q') {
                    return false;
                }
                r -= 1;
                s += 1;
            }
        }
        return true;
    }
    void boss(int i, int n, vector<vector<char>>& m,
              vector<vector<string>>& ans) {
        if (n == i) {
            vector<string> temp;
            for (int p = 0; p < n; p++) {
                string xy(m[p].begin(), m[p].end());
                temp.push_back(xy);
            }
            ans.push_back(temp);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (dia(i, j, n, m) == true && col(i, j, n, m) == true) {
                m[i][j] = 'Q';
                boss(i + 1, n, m, ans);
                m[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> m(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        int i = 0;
        for (int j = 0; j < n; j++) {
            m[0][j] = 'Q';
            boss(i + 1, n, m, ans);
            m[0][j] = '.';
        }
        return ans;
    }
};
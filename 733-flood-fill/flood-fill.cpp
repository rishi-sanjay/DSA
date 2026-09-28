class Solution {
public:
    void call(vector<vector<int>>& image, int i, int j, int color, int x,
              vector<vector<int>>& vis) {
        int n = image.size();
        int m = image[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || image[i][j] != x ||
            vis[i][j] == 1)
            return;
        vis[i][j] = 1;
        image[i][j] = color;
        call(image, i, j + 1, color, x, vis);
        call(image, i, j - 1, color, x, vis);
        call(image, i - 1, j, color, x, vis);
        call(image, i + 1, j, color, x, vis);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        call(image, sr, sc, color, image[sr][sc], vis);
        return image;
    }
};
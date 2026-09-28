class Solution {
public:
    void call(vector<vector<int>>& image, int i, int j, int color, int x) {
        int n = image.size();
        int m = image[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || image[i][j] != x ||
            image[i][j] == color)
            return;
        image[i][j] = color;
        call(image, i, j + 1, color, x);
        call(image, i, j - 1, color, x);
        call(image, i - 1, j, color, x);
        call(image, i + 1, j, color, x);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        call(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};
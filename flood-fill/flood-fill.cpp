class Solution {
    int original;
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (sr < 0 || sc < 0 || sr == image.size() || sc == image[0].size() || image[sr][sc] != original) return;
        image[sr][sc] = newColor;
        dfs(image, sr+1, sc, newColor);
        dfs(image, sr, sc+1, newColor);
        dfs(image, sr-1, sc, newColor);
        dfs(image, sr, sc-1, newColor);
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.size() == 0 || image[sr][sc] == newColor) return image;
        original = image[sr][sc];
        dfs(image, sr, sc, newColor);
        return image;
    }
};
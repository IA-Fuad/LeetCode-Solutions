class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int dfs(vector<vector<int>>& grid, int x, int y) {
        int connected = 0;
        for (int k = 0; k < 4; k++) {
            int i = x + dx[k], j = y + dy[k];
            if (i < 0 or j < 0 or i == grid.size() or j == grid[0].size() or grid[i][j] == 0) continue;
            grid[i][j] = 0;
            connected += (dfs(grid, i, j) + 1);
        }
        
        return connected;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    maxArea = max(maxArea, dfs(grid, i, j) + 1);
                }
            }
        }
        
        return maxArea;
    }
};
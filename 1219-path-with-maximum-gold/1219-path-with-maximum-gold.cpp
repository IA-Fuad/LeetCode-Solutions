class Solution {
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int rec(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == 0) {
            return 0;
        }    
        
        int gold = grid[i][j];
        grid[i][j] = 0;
        
        int maxGold = 0;
        for (int d = 0; d < 4; d++) {
            maxGold = max(maxGold, rec(grid, i + dir[d][0], j + dir[d][1]) + gold);
        }
        grid[i][j] = gold;
        
        return maxGold;
    }
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, rec(grid, i, j));
                }
            }
        }
        
        return maxGold;
    }
};
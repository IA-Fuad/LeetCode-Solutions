class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> pathSum(m+1, vector<int>(n+1, INT_MAX));
        
        pathSum[1][0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pathSum[i][j] = min(pathSum[i][j-1], pathSum[i-1][j]) + grid[i-1][j-1]; 
            }
        }
        
        return pathSum[m][n];
    }
};
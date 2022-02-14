class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> paths(n+1, 0);
        paths[1] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    paths[j+1] = 0;
                }
                else {
                    paths[j+1] += paths[j];
                }
            }
        }
        
        return paths[n];
    }
};
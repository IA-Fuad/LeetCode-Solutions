class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> pathSum(n+1, INT_MAX);
        
        pathSum[1] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pathSum[j] = min(pathSum[j-1], pathSum[j]) + grid[i-1][j-1]; 
                cout << pathSum[j] << ' ';
            }
            cout << endl;
        }
        
        return pathSum[n];
    }
};
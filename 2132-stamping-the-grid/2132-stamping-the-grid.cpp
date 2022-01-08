class Solution {
    void calculatePreSum(vector<vector<int>>& grid, vector<vector<int>>& preSum) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                preSum[i+1][j+1] = grid[i][j] + preSum[i+1][j] + preSum[i][j+1] - preSum[i][j];
            }
        }
    }
    
    int get2dRangeSum(vector<vector<int>>& preSum, int row1, int col1, int row2, int col2) {
        return preSum[row2+1][col2+1] - preSum[row1][col2+1] - preSum[row2+1][col1] + preSum[row1][col1];
    }
     
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> preSum(n+1, vector<int>(m+1, 0)), stamps(n, vector<int>(m, 0));
        calculatePreSum(grid, preSum);
        
        for (int i = stampHeight-1; i < n; i++) {
            for (int j = stampWidth-1; j < m; j++) {
                if (grid[i][j] == 0) {
                    int x = get2dRangeSum(preSum, i-stampHeight+1, j-stampWidth+1, i, j);
                    if (x == 0) stamps[i][j] = 1;
                }
            }
        }
        
        calculatePreSum(stamps, preSum);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    int x = get2dRangeSum(preSum, i, j, min(i+stampHeight, n-1), min(j+stampWidth, m-1));
                    if (x == 0) return false;
                }
            }
        }
        
        return true;
    }
};
class NumMatrix {
    int n, m;
    vector<vector<int>> preSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        preSum.resize(n+1, vector<int>(m+1, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                preSum[i+1][j+1] = matrix[i][j] + preSum[i+1][j] + preSum[i][j+1] - preSum[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2+1][col2+1] - preSum[row1][col2+1] - preSum[row2+1][col1] + preSum[row1][col1];
    }
};

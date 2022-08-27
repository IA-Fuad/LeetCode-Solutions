class Solution {
    vector<vector<int>> prefixSum;
    int m, n;
    
    void calculatePrefixSum(vector<vector<int>>& matrix) {
        prefixSum.resize(m, vector<int>(n));
        
        prefixSum[0][0] = matrix[0][0];
        for (int i = 1; i < m; i++) prefixSum[i][0] = prefixSum[i-1][0] + matrix[i][0];
        for (int j = 1; j < n; j++) prefixSum[0][j] = prefixSum[0][j-1] + matrix[0][j];
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] + matrix[i][j] - prefixSum[i-1][j-1];
            }
        }
    }
    
    int getRectangleSum(int x1, int y1, int x2, int y2) {
        int left = y1 == 0 ? 0 : prefixSum[x2][y1-1];
        int top = x1 == 0 ? 0 : prefixSum[x1-1][y2];
        int corner = (x1 > 0 and y1 > 0) ? prefixSum[x1-1][y1-1] : 0;
        int sum = prefixSum[x2][y2] - (left + top) + corner;
        return sum;
    }
    
    void updateMaxSum(int row1, int col1, int row2, int col2, int k, int& maxSum) {
        int sum = getRectangleSum(row1, col1, row2, col2);
        if (sum <= k) maxSum = max(maxSum, sum);
    }
    
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        m = matrix.size(), n = matrix[0].size();
        calculatePrefixSum(matrix);
        
        int maxSum = INT_MIN;
        
        for (int r1 = 0; r1 < m; r1++) {
            for (int r2 = r1; r2 < m; r2++) {
                set<int> sum;
                sum.insert(0);
                for (int c = 0; c < n; c++) {
                    int currSum = getRectangleSum(r1, 0, r2, c);

                    if (currSum == k) return k;
                    auto it = sum.lower_bound(currSum - k);
                    if (it != sum.end()) {
                        maxSum = max(maxSum, currSum - (*it));
                    }
                    sum.insert(currSum);
                }
            }
        }

        return maxSum;
    }
};


/*

 5 -4 -3  4
-3 -4  4  5
 5  1  5 -4



*/
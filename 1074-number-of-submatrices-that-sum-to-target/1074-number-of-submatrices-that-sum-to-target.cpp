class Solution {
    int m, n;
    vector<vector<int>> getPrefixSum(vector<vector<int>>& matrix) {
        vector<vector<int>> prefixSum(m, vector<int>(n, 0));
        
        prefixSum[0][0] = matrix[0][0];
        for (int i = 1; i < m; i++) prefixSum[i][0] = prefixSum[i-1][0] + matrix[i][0];
        for (int j = 1; j < n; j++) prefixSum[0][j] = prefixSum[0][j-1] + matrix[0][j];
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] + matrix[i][j] - prefixSum[i-1][j-1];
            }
        }
        
        return prefixSum;
    }
    
    int getSubMatrixSum(vector<vector<int>>& prefixSum, int x1, int y1, int x2, int y2) {
        int left = y1 == 0 ? 0 : prefixSum[x2][y1-1];
        int top = x1 == 0 ? 0 : prefixSum[x1-1][y2];
        int corner = (x1 > 0 and y1 > 0) ? prefixSum[x1-1][y1-1] : 0;
        int sum = prefixSum[x2][y2] - (left + top) + corner;
        return sum;
    }
    
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        m = matrix.size(), n = matrix[0].size();
        
        auto prefixSum = getPrefixSum(matrix);
        
        int cnt = 0;
        for (int r1 = 0; r1 < m; r1++) {
            for (int r2 = r1; r2 < m; r2++) {
                unordered_map<int, int> numCount;
                numCount[0]++;
                int currSum = 0;
                for (int c = 0; c < n; c++) {
                    currSum = getSubMatrixSum(prefixSum, r1, 0, r2, c);
                    auto it = numCount.find(currSum - target);
                    if (it != numCount.end()) {
                        cnt += it->second;
                    }
                    numCount[currSum]++;
                }
            }
        }
        
        return cnt;
    }
};
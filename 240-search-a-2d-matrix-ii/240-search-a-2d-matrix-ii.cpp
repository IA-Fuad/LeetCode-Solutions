class Solution {
    int searchRow(vector<vector<int>>& matrix, int row, int target) {
        int col = lower_bound(matrix[row].begin(), matrix[row].end(), target) - matrix[row].begin();
        if (col == matrix[0].size() or (col > 0 and matrix[row][col] > target)) col--;
        return col;
    }
    
    int searchCol(vector<vector<int>>& matrix, int col, int target) {
        int left = 0, right = matrix.size()-1, mid, row = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (matrix[mid][col] <= target) {
                left = mid + 1;
                row = mid;
            }
            else {
                right = mid - 1;
            }
        }
        return row;
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int col = searchRow(matrix, 0, target);
//         int row = searchCol(matrix, col, target);
//         //cout << row << ' ' << col << endl;
//         if (matrix[row][col] == target) return true;
        
//         row = searchCol(matrix, 0, target);
//         col = searchRow(matrix, row, target);
//         //cout << row << ' ' << col << endl;
//         if (matrix[row][col] == target) return true;
        
//         return false;
        
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1;
        
        while (i < m and j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] < target) {
                i++;
            }
            else {
                j--;
            }
        }
        
        return false;
    }
};
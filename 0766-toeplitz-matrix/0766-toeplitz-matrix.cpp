class Solution {
    bool diagonalIsSame(vector<vector<int>>& matrix, int si, int sj) {
        int num = matrix[si][sj];
        while (si < matrix.size() and sj < matrix[0].size()) {
            if (matrix[si][sj] != num) return false;
            si++;
            sj++;
        }
        return true;
    }
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            if (!diagonalIsSame(matrix, i, 0)) return false;
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            if (!diagonalIsSame(matrix, 0, j)) return false;
        }
        return true;
    }
};
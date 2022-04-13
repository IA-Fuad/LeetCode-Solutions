class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool isNotValid(int i, int j, int n, const vector<vector<int>>& sm) {
        return i < 0 or j < 0 or i == n or j == n or sm[i][j] != 0;
    }
    
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> squareMatrix(n, vector<int>(n));
        int i = 0, j = 0, currentMove = 0, x = 1;
        
        while (x <= (n * n)) {
            squareMatrix[i][j] = x++;
            
            if (isNotValid(i + dx[currentMove], j + dy[currentMove], n, squareMatrix)) {
                currentMove++;
                currentMove %= 4;
            }
            
            i += dx[currentMove];
            j += dy[currentMove];
        }
        
        return squareMatrix;
    }
};
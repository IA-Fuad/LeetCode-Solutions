class Solution {
    const int oneToZero = 2;
    const int zeroToOne = 3;
    const int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    const int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

    bool isValidIndex(int m, int n, int i, int j) {
        return i >= 0 and j >= 0 and i < m and j < n;
    }
    
    void changeState(vector<vector<int>>& board, int i, int j, int liveNeighbors) {
        if (liveNeighbors < 2 or liveNeighbors > 3) {
            board[i][j] = board[i][j] == 1 ? oneToZero : 0;
        }
        else if (liveNeighbors == 3) {
            board[i][j] = board[i][j] == 0 ? zeroToOne : 1;
        }
    }
    
    void nextStateOfCell(vector<vector<int>>& board, int i, int j) {
        int liveNeighbors = 0;
        
        for (int k = 0; k < 8; k++) {
            int x = dx[k] + i;
            int y = dy[k] + j;

            if (isValidIndex(board.size(), board[0].size(), x, y) and (board[x][y] == 1 or board[x][y] == oneToZero)) {
                liveNeighbors++;
            }
        }
        
        changeState(board, i, j, liveNeighbors);
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nextStateOfCell(board, i, j);
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == oneToZero) board[i][j] = 0;
                else if (board[i][j] == zeroToOne) board[i][j] = 1;
            }
        }
    }
};
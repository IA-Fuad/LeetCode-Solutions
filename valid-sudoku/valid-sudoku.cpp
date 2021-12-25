class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> row, col;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    char x = board[i][j];
                    auto itx = row.find(x);
                    if (itx != row.end()) return false;
                    row[board[i][j]] = 1;
                }
                if (board[j][i] != '.') {
                    char y = board[j][i];
                    auto ity = col.find(y);
                    if (ity != col.end()) return false;
                    col[board[j][i]] = 1;
                }  
            }
        }
        for (int i = 3; i <= 9; i+=3) {
            for (int j = 3; j <= 9; j+=3) {
                unordered_map<char, int> mark;
                for (int k = i-3; k < i; k++) {
                    for (int l = j-3; l < j; l++) {
                        if (board[k][l] == '.') continue;
                        auto it = mark.find(board[k][l]);
                        if (it != mark.end()) return false;
                        mark[board[k][l]] = 1;
                    }
                }
            }
        }
        return true;
    }
};
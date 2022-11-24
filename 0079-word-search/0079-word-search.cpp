class Solution {
    int dir[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    bool rec(vector<vector<char>>& board, const string& word, int i, int j, int k) {
        if (k == word.size()) return true;
        if (i < 0 or j < 0 or i == board.size() or j == board[0].size() or board[i][j] != word[k]) return false;
        char curr = board[i][j];
        board[i][j] = '0';
        
        bool ex = false;
        for (int d = 0; d < 4; d++) {
            if (rec(board, word, i+dir[d][0], j+dir[d][1], k+1)) {
                ex = true;
                break;
            }
        }
        board[i][j] = curr;
        
        return ex;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> startIndices;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    startIndices.push_back({i, j});
                }
            }
        }
        
        for (auto&[i, j] : startIndices) {
            if (rec(board, word, i, j, 0)) return true;
        }
        return false;
    }
};
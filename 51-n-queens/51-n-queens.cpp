class Solution {
    typedef unordered_set<int> uiset;
    
    int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
    
    bool placeOrUnplaceQueen(vector<string>& comb, vector<vector<int>>& vis, int n, int i, int j, char p) {
        if (vis[i][j] and p == 'Q') {
            cout << i << ' ' << j << endl;
            return false;
        }
        comb[i][j] = p;
        int isVisited = p == 'Q' ? 1 : -1;

        for (int k = 0; k < 8; k++) {
            int x = i, y = j;
            while (x >= 0 and y >= 0 and x < n and y < n) {
                vis[x][y] += isVisited;
                x += dx[k];
                y += dy[k];
            }
        }
        
        return true;
    }
    
    void rec(int n, vector<vector<string>>& validCombs, tuple<uiset, uiset, uiset>& flag, vector<string>& comb, int row) {
        if (row == n) {
            validCombs.push_back(comb);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            auto&[colFlag, diagFlag, antiDiagFlag] = flag;
            int diag = row - col, antiDiag = row + col;
        
            if (colFlag.find(col) == colFlag.end() and diagFlag.find(diag) == diagFlag.end() and antiDiagFlag.find(antiDiag) == antiDiagFlag.end()) {
                comb[row][col] = 'Q';
                colFlag.insert(col);
                diagFlag.insert(diag);
                antiDiagFlag.insert(antiDiag);
                
                rec(n, validCombs, flag, comb, row + 1);
                
                comb[row][col] = '.';
                colFlag.erase(col);
                diagFlag.erase(diag);
                antiDiagFlag.erase(antiDiag);
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        string row(n, '.');
        vector<vector<string>> validCombs;
        vector<string> validComb(n, row);
        tuple<uiset, uiset, uiset> flag;
        
        rec(n, validCombs, flag, validComb, 0);
        
        return validCombs;
    }
};
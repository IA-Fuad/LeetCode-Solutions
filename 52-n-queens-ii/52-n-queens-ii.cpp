class Solution {
    typedef unordered_set<int> uiset;
    int ans = 0;
    
    void rec(int n, int row, uiset& colFlag, uiset& diagFlag, uiset& antiDiagFlag) {
        if (row == n) {
            ans++;
            return;
        }
        for (int col = 0; col < n; col++) {
            int diag = row - col, antiDiag = row + col;
            if (colFlag.find(col) == colFlag.end() and diagFlag.find(diag) == diagFlag.end() and antiDiagFlag.find(antiDiag) == antiDiagFlag.end()) {
                colFlag.insert(col);
                diagFlag.insert(diag);
                antiDiagFlag.insert(antiDiag);
                
                rec(n, row + 1, colFlag, diagFlag, antiDiagFlag);
                
                colFlag.erase(col);
                diagFlag.erase(diag);
                antiDiagFlag.erase(antiDiag);
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        uiset colFlag, diagFlag, antiDiagFlag;
        rec(n, 0, colFlag, diagFlag, antiDiagFlag);
        return ans;
    }
};
class Solution {
    vector<vector<string>> ans;
    unordered_set<int> leftDiag, rightDiag;
    
    void rec(int n, int row, int colTaken, vector<string>& queens) {
        if (row == n) {
            ans.push_back(queens);        
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (((colTaken >> col) & 1) or leftDiag.count(row - col) > 0 or rightDiag.count(row + col) > 0) continue;
            
            queens[row][col] = 'Q';
            colTaken ^= (1 << col);
            leftDiag.insert(row - col);
            rightDiag.insert(row + col);
            
            rec(n, row + 1, colTaken, queens);
            
            queens[row][col] = '.';
            colTaken ^= (1 << col);
            leftDiag.erase(row - col);
            rightDiag.erase(row + col);
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> queens(n, string(n, '.'));
        int colTaken = 1 << (n + 1);
        
        rec(n, 0, colTaken, queens);
        
        return ans;
    }
};

/*

Q...
.Q..
..Q.
...Q

*/
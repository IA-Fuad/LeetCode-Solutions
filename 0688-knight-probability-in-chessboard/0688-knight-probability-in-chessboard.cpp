class Solution {
    int dir[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
    vector<vector<vector<double>>> dp;
    
    double rec(int n, int k, int r, int c) {
        if (r < 0 or c < 0 or r >= n or c >= n) return 0;
        if (k == 0) return 1;
        if (dp[r][c][k] != -1) return dp[r][c][k];
        
        double prob = 0;
        for (int d = 0; d < 8; d++) {
            prob += rec(n, k-1, r + dir[d][0], c + dir[d][1]);
        }
        return dp[r][c][k] = prob / 8.0;
    }
    
public:
    double knightProbability(int n, int k, int row, int column) {
        dp.resize(n, vector<vector<double>>(n, vector<double>(k+1, -1)));
        return rec(n, k, row, column);
    }
};
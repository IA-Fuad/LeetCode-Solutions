class Solution {
    const int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int rec(int m, int n, int move, int i, int j) {
        if (i < 0 or j < 0 or i == m or j == n) return 1;
        if (move == 0) return 0;

        int& ref = dp[i][j][move];
        if (ref != -1) return ref;
        
        int paths = 0;
        for (int k = 0; k < 4; k++) {
            paths = (paths + (rec(m, n, move-1, i+dx[k], j+dy[k]) % mod)) % mod;
        }

        return ref = paths;
    }
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.resize(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+2, -1)));
        for (int move = 1; move <= maxMove; move++) {
            rec(m, n, move, startRow, startColumn);
        }
        
        return dp[startRow][startColumn][maxMove] == -1 ? 0 : dp[startRow][startColumn][maxMove];
    }
};
class Solution {
    const int mod = 1e9 + 7;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int rec(vector<vector<vector<int>>>& dp, int i, int j, int m, int n, int move) {
        if (i < 0 || j < 0 || i == m || j == n) return 1;
        if (move == 0) return 0;
        if (dp[i][j][move] != -1) return dp[i][j][move];
        
        int paths = 0;
        for (int k = 0; k < 4; k++) {
            int p = rec(dp, i+dx[k], j+dy[k], m, n, move-1);
            paths = (paths + p) % mod;
        }
        
        return dp[i][j][move] = paths % mod;
    }
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        // return rec(dp, startRow, startColumn, m, n, maxMove);
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, 0)));
        
        dp[startRow][startColumn][0] = 1;
        int paths = 0;
        
        for (int move = 0; move < maxMove; move++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x < 0 || y < 0 || x == m || y == n) {
                            paths += dp[i][j][move];
                            paths %= mod;
                        }
                        else {
                            dp[x][y][move+1] += dp[i][j][move];
                            dp[x][y][move+1] %= mod;
                        }
                    }
                }
            }
        }
        
        return paths;
    }
};
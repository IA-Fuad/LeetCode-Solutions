class Solution {
    int dp[51][51][51][51];
    bool isValid = false;
    
    int rec(int i1, int j1, int i2, int j2, vector<vector<int>>& grid) {
        int n = grid.size();
        if (max({i1, j1, i2, j2}) >= n or grid[i1][j1] == -1 or grid[i2][j2] == -1) {
            return INT_MIN;
        }
        
        if ((i1 == n-1 and j1 == n-1) or (i2 == n-1 and j2 == n-1)) return grid[i1][j1];
        if (dp[i1][j1][i2][j2] != -1) return dp[i1][j1][i2][j2];
        
        int a = rec(i1+1, j1, i2+1, j2, grid);
        int b = rec(i1+1, j1, i2, j2+1, grid);
        int c = rec(i1, j1+1, i2+1, j2, grid);
        int d = rec(i1, j1+1, i2, j2+1, grid);

        int mx = max({a, b, c, d});
        
        mx += ((i1 == i2 and j1 == j2) ? grid[i1][j1] : grid[i1][j1] + grid[i2][j2]);

        return dp[i1][j1][i2][j2] = mx;
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        return max(0, rec(0, 0, 0, 0, grid));
    }
};
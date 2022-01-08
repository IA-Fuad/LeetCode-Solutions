class Solution {
    int n, m;
    vector<vector<vector<int>>> dp;
    int rec(vector<vector<int>>& grid, int i, int j1, int j2) {
        if (i == n || j1 < 0 || j2 < 0 || j1 == m || j2 == m) return 0;
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int mx = 0;
        for (int k = j1-1; k <= j1+1; k++) {
            for (int l = j2-1; l <= j2+1; l++) {
                int totalSum = rec(grid, i+1, k, l) + grid[i][j1];
                if (j1 != j2) totalSum += grid[i][j2];
                mx = max(mx, totalSum);
            }
        }
        return dp[i][j1][j2] = mx;
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return rec(grid, 0, 0, m-1);
    }
};
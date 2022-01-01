class Solution {
    int dp[200][200];
    int rec(vector<vector<int>>& triangle, int i, int j, int n) {
        if (i == n || j > i) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int x = min(rec(triangle, i+1, j, n), rec(triangle, i+1, j+1, n));
        dp[i][j] = x + triangle[i][j];
        return dp[i][j];
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        // for (int i = 1; i < m; i++) {
        //     int n = triangle[i].size();
        //     for (int j = 0; j < n; j++) {
        //         triangle[i][j] += min(triangle[i-1][min(n-2,j)], triangle[i-1][max(0,j-1)]);
        //     }
        // }
        // return *min_element(triangle[m-1].begin(), triangle[m-1].end());
        memset(dp, -1, sizeof dp);
        return rec(triangle, 0, 0, m);
    }
};
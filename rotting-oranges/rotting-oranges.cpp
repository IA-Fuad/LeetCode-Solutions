class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        int fresh = 0;
        
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
                if (grid[i][j] == 1) fresh++;
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int ans = 0;
        
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int x = u.first + dx[i];
                int y = u.second + dy[i];
                if (x < 0 || y < 0 || x == m || y == n) continue;
                if (grid[x][y] == 1 && dist[x][y] > dist[u.first][u.second] + 1) {
                    dist[x][y] = dist[u.first][u.second] + 1;
                    q.push({x, y});
                    fresh--;
                    ans = max(ans, dist[x][y]);
                }
            }
        }
        
        ans = fresh > 0 ? -1 : ans;
        return ans;
    }
};
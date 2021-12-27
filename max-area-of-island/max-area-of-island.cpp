class Solution {
    
    int dirx[4] = {0, 0, 1, -1};
    int diry[4] = {1, -1, 0, 0};
    bool vis[50][50];
    
    int getArea(vector<vector<int>>& grid, pair<int,int> s) {
        if (vis[s.first][s.second] || grid[s.first][s.second] == 0) return 0;
        int area = 1;
        queue<pair<int,int>> q;
        q.push(s);
        vis[s.first][s.second] = true;
        
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int x = u.first + dirx[i];
                int y = u.second + diry[i];
                if (x == grid.size() || y == grid[0].size() || x < 0 || y < 0 || grid[x][y] == 0 || vis[x][y]) continue;
                q.push({x,y});
                vis[x][y] = true;
                area++;
            }
        }
        return area;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = INT_MIN;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                mx = max(mx, getArea(grid, {i,j}));
            }
        }
        return mx;
    }
};
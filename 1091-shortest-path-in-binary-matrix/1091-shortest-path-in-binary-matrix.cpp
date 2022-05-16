class Solution {
    int dx[8] = {0, 0, 1, -1, 1, -1, -1, 1};
    int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    
    bool isValidCell(int i, int j, vector<vector<int>>& grid) {
        return !(i < 0 or j < 0 or i == grid.size() or j == grid.size() or grid[i][j] != 0);
    }
    
    int bfs(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        
        queue<tuple<int, int, int>> Q;
        Q.push({0, 0, 0});
        
        while (!Q.empty()) {
            auto[x, y, d] = Q.front();
            Q.pop();
            
            for (int k = 0; k < 8; k++) {
                int i = x + dx[k], j = y + dy[k];
                
                if (i == grid.size() and i == j) return d + 1;
                
                if (isValidCell(i, j, grid)) {
                    Q.push({i, j, d+1});
                    grid[i][j] = 1;
                }
            }
        }
        
        return -1;
    }
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
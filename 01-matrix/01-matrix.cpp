class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    vector<vector<int>> dist;
    vector<vector<int>> vis;
    
    void bfs(vector<vector<int>>& mat, pair<int, int> s) {
        queue<pair<int, int>> q;
        q.push(s);
        dist[s.first][s.second] = 0;
        
        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = u.first + dx[i];
                int y = u.second + dy[i];
                if (x < 0 || y < 0 || x == mat.size() || y == mat[0].size()) continue;
                if (mat[x][y] == 0) {
                    dist[x][y] = 0;
                    q.push({x, y});
                    mat[x][y] = -1;
                }
                else if (mat[x][y] == 1 && dist[x][y] > dist[u.first][u.second] + 1) {
                    dist[x][y] = dist[u.first][u.second] + 1;
                    q.push({x, y});
                }
            }
        }
    }
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        dist.resize(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    bfs(mat, {i, j});
                    goto ret;
                }
            }
        }
        ret:
            return dist;
    }
};
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        auto isEmpty = [](int state)->bool {
            return state == 2147483647;
        };
        int m = rooms.size();
        int n = rooms[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        queue<tuple<int, int, int>> Q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    Q.push({i, j, 0});
                }
            }
        }
        
        while (!Q.empty()) {
            auto[x, y, dist] = Q.front();
            Q.pop();
            
            for (int k = 0; k < 4; k++) {
                int i = dx[k] + x;
                int j = dy[k] + y;
                
                if (i < 0 or j < 0 or i == m or j == n or rooms[i][j] == -1 or rooms[i][j] == 0) continue;
                if (isEmpty(rooms[i][j])) {
                    rooms[i][j] = dist + 1;
                    Q.push({i, j, dist + 1});
                }
            }
        }
    }
};
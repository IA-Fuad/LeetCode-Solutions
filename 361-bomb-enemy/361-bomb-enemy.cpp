class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), mx = 0;
        vector<int> enemyInColumns(n);
        
        for (int i = 0; i < m; i++) {
            int enemyInTheRow = 0;
            bool hasEmptyCell = false;
            
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'W') {
                    enemyInTheRow = 0;
                }
                else {
                    if (j == 0 || grid[i][j-1] == 'W') {
                        for (int k = j; k < n && grid[i][k] != 'W'; k++) {
                            enemyInTheRow += grid[i][k] == 'E';
                        }
                    }
                    if (i == 0 || grid[i-1][j] == 'W') {
                        int enemies = 0;
                        for (int k = i; k < m && grid[k][j] != 'W'; k++) {
                            enemies += grid[k][j] == 'E';
                        }
                        enemyInColumns[j] = enemies;
                    }
                }
                
                if (grid[i][j] == '0') {
                    mx = max(mx, enemyInTheRow + enemyInColumns[j]);
                }
                //cout << enemyInTheRow << ' ' << enemyInColumns[j] << "    ";
            }
            //cout << endl;
        }
        
        return mx;
    }
};
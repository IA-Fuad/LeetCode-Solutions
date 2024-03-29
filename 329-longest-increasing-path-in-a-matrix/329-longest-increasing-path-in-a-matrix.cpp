class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int m, n, longestIncreasingPathLen;
    vector<vector<int>> longestIncreasingLen;
    
    int rec(vector<vector<int>>& matrix, int i, int j, int (*comparator)(int, int)) {
        if (i < 0 || j < 0 || i == m || j == n) return 0;
        if (longestIncreasingLen[i][j] != -1) {
            return longestIncreasingLen[i][j];
        }
        
        int t, b, r, l;
        t = b = r = l = 1;
        
        if (i+1 < m && comparator(matrix[i+1][j], matrix[i][j])) {
            t = rec(matrix, i+1, j, comparator) + 1;
        }
        if (i-1 >= 0 && comparator(matrix[i-1][j], matrix[i][j])) {
            b = rec(matrix, i-1, j, comparator) + 1;
        }
        if (j+1 < n && comparator(matrix[i][j+1], matrix[i][j])) {
            r = rec(matrix, i, j+1, comparator) + 1;
        }
        if (j-1 >= 0 && comparator(matrix[i][j-1], matrix[i][j])) {
            l = rec(matrix, i, j-1, comparator) + 1;
        }
        
        return longestIncreasingLen[i][j] = max({t, b, r, l});
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
//         longestIncreasingLen.resize(m, vector<int>(n, -1));
        
//         auto increasingComparator = [](int x, int y) -> int {
//             return x > y;
//         };
//         auto decreasingCompartor = [](int x, int y) -> int {
//             return x < y;
//         };
        
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 longestIncreasingPathLen = max(longestIncreasingPathLen, rec(matrix, i, j, increasingComparator));
//             }
//         }
        
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 cout << longestIncreasingLen[i][j] << ' ';
//             }
//             cout << endl;
//         }
        vector<vector<int>> outDegree(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || y < 0 || x == m || y == n) continue;
                    outDegree[i][j] += (matrix[x][y] > matrix[i][j]);
                }
            }
        }
        
        deque<pair<int, int>> leaves;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (outDegree[i][j] == 0) {
                    leaves.push_back({i, j});
                }
            }
        }
        
        while (!leaves.empty()) {
            longestIncreasingPathLen++;
            int currentLeaves = leaves.size();
            
            while (currentLeaves > 0) {
                int i = leaves.front().first;
                int j = leaves.front().second;
                leaves.pop_front();
                currentLeaves--;
                
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || y < 0 || x == m || y == n) continue;

                    if (matrix[x][y] < matrix[i][j]) {
                        outDegree[x][y]--;
                        if (outDegree[x][y] == 0) {
                            leaves.push_back({x, y});
                        }
                    }
                }
            }
        }
        
        return longestIncreasingPathLen;
    }
};
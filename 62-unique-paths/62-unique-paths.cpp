class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n < m) swap(m, n);
        vector<int> paths(n+1, 0);
        
        paths[1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                paths[j] = paths[j] + paths[j-1];
            }
        }
        
        return paths[n];
    }
};
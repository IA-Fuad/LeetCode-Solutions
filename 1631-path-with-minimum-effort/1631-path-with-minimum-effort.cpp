class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    vector<vector<bool>> vis;
    
    bool isValid(int i, int j, vector<vector<int>>& grid) {
        return !(i < 0 or j < 0 or i == grid.size() or j == grid[0].size());
    }
    
    bool rec(vector<vector<int>>& grid, int i, int j, int k) {
        if (i == grid.size()-1 and j == grid[0].size()-1) {
            return true;
        }
        
        vis[i][j] = true;
        for (int d = 0; d < 4; d++) {
            int ii = i + dx[d], jj = j + dy[d];

            
            if (isValid(ii, jj, grid) and !vis[ii][jj] and abs(grid[ii][jj] - grid[i][j]) <= k) {
                //cout << ii << ' ' << jj << endl;
                if (rec(grid, ii, jj, k)) {
                    return true;
                }   
            }
        }
        
        return false;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int lo = 0, hi = 1000000, ans;
        
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            vis.resize(0, vector<bool>(0, false));
            vis.resize(heights.size(), vector<bool>(heights[0].size(), false));

            if (rec(heights, 0, 0, mid)) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
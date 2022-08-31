class Solution {
    int direction[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<vector<bool>>> cellCanReach;
    vector<vector<int>> ans;
    
    int pacific = 0, atlantic = 1;
    
    void dfs(vector<vector<int>>& heights, int i, int j, int ocean) {
        if (cellCanReach[i][j][ocean]) return;
        
        cellCanReach[i][j][ocean] = true;
        
        if (cellCanReach[i][j][pacific] and cellCanReach[i][j][atlantic]) {
            ans.push_back({i, j});
        }
        
        for (int d = 0; d < 4; d++) {
            int ii = i + direction[d][0], jj = j + direction[d][1];
            
            if (ii < 0 or jj < 0 or ii == heights.size() or jj == heights[0].size() or heights[ii][jj] < heights[i][j]) continue;
            dfs(heights, ii, jj, ocean);
        }
    }
    
    void traverseFromOcean(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        cellCanReach.resize(row, vector<vector<bool>>(col, vector<bool>(2)));
        
        for (int i = 0; i < row; i++) {
            dfs(heights, i, 0, pacific);
            dfs(heights, i, col-1, atlantic);
        }
        for (int j = 0; j < col; j++) {
            dfs(heights, 0, j, pacific);
            dfs(heights, row-1, j, atlantic);
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        traverseFromOcean(heights);
        
        return ans;
    }
};
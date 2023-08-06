class Solution {
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int getInfectionCount(vector<vector<int>>& grid, vector<vector<int>>& isVis, vector<pair<int, int>>& areaCells, int areaCode, int i, int j) {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or isVis[i][j] == areaCode or grid[i][j] == 2) {
            return 0;
        }

        isVis[i][j] = areaCode;
        if (grid[i][j] == 0) {
            return 1;
        }
        
        areaCells.push_back({i, j});
        
        int infectedCellsCount = 0;
        for (int d = 0; d < 4; d++) {
            infectedCellsCount += getInfectionCount(grid, isVis, areaCells, areaCode, i + dir[d][0], j + dir[d][1]);
        }
        
        return infectedCellsCount;
    }
    
    int infectAndGetWallCount(vector<vector<int>>& grid, vector<pair<int, int>>& areaCells, bool infect) {
        int wallCount = 0;
        
        for (auto[i, j] : areaCells) {
            if (!infect) {
                grid[i][j] = 2;
            }
            for (int d = 0; d < 4; d++) {
                int ii = i + dir[d][0];
                int jj = j + dir[d][1];
                
                if (ii < 0 or jj < 0 or ii >= grid.size() or jj >= grid[0].size()) continue;
                
                if (grid[ii][jj] == 0) {
                    if (infect) {
                        grid[ii][jj] = 1;
                    }
                    else {
                        wallCount++;
                    }
                }
            }
        }
        
        return wallCount;
    }
    
public:
    int containVirus(vector<vector<int>>& isInfected) {
        int m = isInfected.size(), n = isInfected[0].size(), totalWalls = 0;
        
        while (true) {
            int maxInfectionCount = 0, maxArea = -1;
            vector<vector<pair<int, int>>> areas;
            vector<vector<int>> isVis(m, vector<int>(n, 0));
            int areaCode = 1;

            for (int i = 0; i < m; i++) { 
                for (int j = 0; j < n; j++) {
                    if (isInfected[i][j] == 1 and isVis[i][j] == 0) {
                        vector<pair<int, int>> areaCells;
                        int infectionCount = getInfectionCount(isInfected, isVis, areaCells, areaCode, i, j);
                        areaCode++;
                        
                        if (infectionCount > maxInfectionCount) {
                            maxInfectionCount = infectionCount;
                            maxArea = areas.size();
                        }
                        areas.push_back(areaCells);
                    }
                }
            }
            
            if (maxArea == -1) break;
            
            totalWalls += infectAndGetWallCount(isInfected, areas[maxArea], false);
            for (int i = 0; i < areas.size(); i++) {
                if (i == maxArea) continue;
                infectAndGetWallCount(isInfected, areas[i], true);
            }
        }
        
        return totalWalls;
    }
};

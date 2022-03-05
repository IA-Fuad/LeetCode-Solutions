class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> hp(m+1, vector<int>(n+1, INT_MAX));

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 and j == n-1) {
                    hp[i][j] = dungeon[i][j] > 0 ? 1 : (-dungeon[i][j] + 1);
                    continue;
                }
                
                int minAdj = min(hp[i][j+1], hp[i+1][j]);
                if (dungeon[i][j] > 0) {
                    hp[i][j] = max(1, minAdj - dungeon[i][j]);
                }
                else {
                    hp[i][j] = -dungeon[i][j] + minAdj;
                }
            }
        }
        
        return hp[0][0];
    }
};

/* 

[-2, -3, 3]
[-5, -10, 5]
[10, 1, 6]



*/
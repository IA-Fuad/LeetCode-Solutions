class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> hp(n+1, INT_MAX);
        vector<int> nextRowHp(n+1, INT_MAX);

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 and j == n-1) {
                    hp[j] = dungeon[i][j] > 0 ? 1 : (-dungeon[i][j] + 1);
                    continue;
                }
                
                int minAdj = min(hp[j+1], nextRowHp[j]);
                if (dungeon[i][j] > 0) {
                    hp[j] = max(1, minAdj - dungeon[i][j]);
                }
                else {
                    hp[j] = -dungeon[i][j] + minAdj;
                }
            }
            nextRowHp = hp;
        }
        
        return hp[0];
    }
};

/* 

[-2, -3, 3]
[-5, -10, 5]
[10, 1, 6]



*/
class Solution {
public:
    bool judgeCircle(string moves) {
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int movD[100];
        movD['D'] = 0, movD['U'] = 1, movD['R'] = 2, movD['L'] = 3;
        
        int x = 0, y = 0;
        
        for (char move : moves) {
            x += dir[movD[move]][0];
            y += dir[movD[move]][1];
        }
        
        return x == 0 and y == 0;
    }
};
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {1, 0, -1, 0};
        int ci = 0, i = 0, j = 0;
        
        for (char ins : instructions) {
            if (ins == 'G') {
                i += dx[ci];
                j += dy[ci];
            }
            else if (ins == 'L') ci++;
            else ci--;
            if (ci < 0) ci = 3;
            if (ci > 3) ci = 0;
        }
        
        if ((i == 0 && j == 0) || ci != 0) return true;
        return false;
    }
}; 
    
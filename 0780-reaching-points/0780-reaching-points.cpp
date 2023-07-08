class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx and ty >= sy) {
            if (tx == ty) break;
            if (tx > ty) {
                if (ty == sy) return (tx - sx) % ty == 0;
                tx %= ty;
            }
            else {
                if (tx == sx) return (ty - sy) % tx == 0;
                ty %= tx;
            }
        }
        
        return tx == sx and ty == sy;
    }
};
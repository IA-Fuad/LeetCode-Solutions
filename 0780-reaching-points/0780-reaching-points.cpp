class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx and ty >= sy) {
            if (ty > tx) {
                if (sx == tx) return (ty - sy) % sx == 0;
                ty %= tx;
            }
            else {
                if (sy == ty) return (tx - sx) % sy == 0;
                tx %= ty;
            }
        }
        return sx == tx and sy == ty;
    }
};
class Solution {
public:
    int climbStairs(int n) {
        int ways = 0, prev = 1, prevPrev = 0;
        
        for (int i = 1; i <= n; i++) {
            ways = prev + prevPrev;
            prevPrev = prev;
            prev = ways;
        }
        
        return ways;
    }
};
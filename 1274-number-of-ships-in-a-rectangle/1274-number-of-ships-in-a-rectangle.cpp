/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
    int rec(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        if (bottomLeft[0] > topRight[0] || bottomLeft[1] > topRight[1] || !sea.hasShips(topRight, bottomLeft)) {
            return 0;
        }
        if (topRight[0] == bottomLeft[0] && topRight[1] == bottomLeft[1]) return 1;
        int midx = (topRight[0] + bottomLeft[0]) / 2;
        int midy = (topRight[1] + bottomLeft[1]) / 2;

        int a = rec(sea, topRight, {midx+1, midy+1});
        int b = rec(sea, {midx, midy}, bottomLeft);
        int c = rec(sea, {topRight[0], midy}, {midx+1, bottomLeft[1]});
        int d = rec(sea, {midx, topRight[1]}, {bottomLeft[0], midy+1});
        
        return a + b + c + d;
    }
    
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        return rec(sea, topRight, bottomLeft);
    }
};
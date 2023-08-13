class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int cost = 0;
        int ri = startPos[0], rj = startPos[1];
        int hi = homePos[0], hj = homePos[1];

        while (ri != hi) {
            if (ri > hi) ri--;
            else ri++;
            cost += rowCosts[ri];
        }
        while (rj != hj) {
            if (rj > hj) rj--;
            else rj++;
            cost += colCosts[rj];
        }
        
        return cost;
    }
};
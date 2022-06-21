class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> Q;
        int totalSteps = 0, i;
        
        for (i = 1; i < heights.size(); i++) {
            if (heights[i] > heights[i-1]) {
                int steps = heights[i] - heights[i-1];
                Q.push(steps);
                
                if (Q.size() > ladders) {
                    bricks -= Q.top();
                    Q.pop();
                    
                    if (bricks < 0) break;
                }
            }
        }
        
        return i-1;
    }
};

/*

5 3 5 

8 5 15 2 16

8 13 28 30 46

*/
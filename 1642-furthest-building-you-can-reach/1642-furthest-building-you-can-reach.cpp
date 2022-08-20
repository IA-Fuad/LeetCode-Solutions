class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> Q;
        
        for (int i = 1; i < heights.size(); i++) {
            int jump = heights[i] - heights[i-1];
            if (jump <= 0) continue;
            
            if (ladders > 0) {
                Q.push(jump);
                ladders--;
            }
            else if (bricks > 0 and !Q.empty()) {
                int smallestJumpTillNow = Q.top();
                bricks -= min(jump, smallestJumpTillNow);
                
                if (bricks < 0) return i - 1;

                if (smallestJumpTillNow < jump) {
                    Q.pop();
                    Q.push(jump);
                }
            }
            else if (bricks > 0) {
                bricks -= jump;
                
                if (bricks < 0) return i - 1;
            }
            else {
                return i - 1;
            }
        }
        
        return heights.size()-1;
    }
};

/*

0 0 5 5 8 13 13

*/
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> S;
        S.push(-1);
        S.push(0);
        int water = 0;
        
        for (int i = 1; i < height.size(); i++) {
            while (S.top() != -1 and height[S.top()] <= height[i]) {
                int prev = S.top();
                S.pop();
                int prevPrev = S.top();
                if (prevPrev == -1) {
                    break;
                }
                //S.pop();
                
                int prevH = height[prev];
                int prevPrevH = height[prevPrev];
                int curr = height[i];
                
                water += ((min(curr, prevPrevH) - prevH) * (i - prevPrev - 1));
            }
            S.push(i);
            
            //cout << i << ' ' << water << endl;
        }
        
        return water;
    }
};
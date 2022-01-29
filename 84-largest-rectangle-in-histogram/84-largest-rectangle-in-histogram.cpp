class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        int mxArea = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            if (s.top() == -1 || heights[i] > heights[s.top()]) s.push(i);
            else {
                while (s.top() != -1 && heights[s.top()] >= heights[i]) {
                    int current = s.top();
                    s.pop();
                    mxArea = max(mxArea, (i - s.top() - 1) * heights[current]);
                }
                s.push(i);
            }
        }
        
        int rightLimit = heights.size();
        while (s.top() != -1) {
            int current = s.top();
            s.pop();
            mxArea = max(mxArea, (rightLimit - s.top() - 1) * heights[current]);
        }
        
        return mxArea;
    }
};
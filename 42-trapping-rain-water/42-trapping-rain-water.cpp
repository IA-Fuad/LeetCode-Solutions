class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> bars;
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!bars.empty() and height[i] > height[bars.top()]) {
                int middleBar = bars.top();
                bars.pop();
                
                if (bars.empty()) break;
                
                int leftBar = bars.top();
                int rightBar = i;
                int boundedHeight = min(height[leftBar], height[rightBar]) - height[middleBar];
                int distance = rightBar - leftBar - 1;
                
                ans += (distance * boundedHeight);
            }
            bars.push(i);
        }
        
        return ans;
    }
};

/*

3-7
1-6
2-3

*/
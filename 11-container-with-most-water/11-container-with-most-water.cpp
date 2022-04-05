class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        
        vector<pair<int, int>> heights;
        
        for (int i = 0; i < height.size(); i++) {
            if (heights.size() == 0 or heights.back().first < height[i]) {
                heights.push_back({height[i], i});
            }
            else {
                for (auto h : heights) {
                    auto[hi, dis] = h;
                    ans = max(ans, min(hi, height[i]) * (i - dis));
                }
            }
        }
        
        heights.clear();
        
        for (int i = height.size()-1; i >= 0; i--) {
            if (heights.size() == 0 or heights.back().first < height[i]) {
                heights.push_back({height[i], i});
            }
            else {
                for (auto h : heights) {
                    auto[hi, dis] = h;
                    ans = max(ans, min(hi, height[i]) * (dis - i));
                }
            }
        }
        
        return ans;
    }
};

/*

1,1
8,2
10,7
7,9

*/
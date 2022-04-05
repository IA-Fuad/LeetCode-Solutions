class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN, i = 0, j = height.size()-1;
        
        while (i < j) {
            ans = max(ans, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) i++;
            else j--;
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
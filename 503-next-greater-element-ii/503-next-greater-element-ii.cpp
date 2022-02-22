class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> greaterElements(n, -1);
        stack<int> elements;
        elements.push(0);
        
        for (int i = 0; i < n; i++) {
            while (!elements.empty()) {
                int ind = elements.top();
                if (nums[ind] >= nums[i]) break;
                greaterElements[ind] = nums[i];
                elements.pop();
            }
            elements.push(i);
        }
        
        for (int i = 0; i < n && !elements.empty(); i++) {
            while (!elements.empty()) {
                int ind = elements.top();
                if (nums[ind] >= nums[i]) break;
                greaterElements[ind] = nums[i];
                elements.pop();
            }
        }
        
        return greaterElements;
    }
};
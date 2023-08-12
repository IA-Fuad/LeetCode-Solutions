class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> Q;
        int n = nums.size();
        vector<int> ans;
        
        for (int i = 0; i < k-1; i++) Q.push({nums[i], i});
        
        for (int i = k-1; i < n; i++) {
            Q.push({nums[i], i});
            int leftBound = i - k + 1;
            
            while (Q.top().second < leftBound) {
                Q.pop();    
            }
            ans.push_back(Q.top().first);
        }
        
        return ans;
    }
};
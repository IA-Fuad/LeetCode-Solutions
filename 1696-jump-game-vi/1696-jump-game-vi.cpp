class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> Q;
        Q.push({nums[n-1], n-1});
        int sum = nums[n-1];
        
        for (int i = n-2; i >= 0; i--) {
            while (!Q.empty() and Q.top().second - i > k) {
                Q.pop();
            }
            sum = Q.top().first + nums[i];
            Q.push({sum, i});
        }
        
        return sum;
    }
};
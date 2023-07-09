class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int64_t> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        dq.push_back(0);
        int len = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (prefixSum[i] >= k) {
                len = min(len, i+1);
            }
            
            while (!dq.empty() and prefixSum[i] - prefixSum[dq.front()] >= k) {
                len = min(len, i - dq.front());
                dq.pop_front();
            }
            
            while (!dq.empty() and prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        return len == INT_MAX ? -1 : len;
    }
};

/*

2 -1 5

2 1 5

1 

*/
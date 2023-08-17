class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<int64_t, int>> Q;
        int n = nums.size(), len = INT_MAX;
        int64_t preSum = 0;

        Q.push_back({nums[0], 0});
        
        for (int i = 0; i < n; i++) {
            preSum += nums[i];
            if (preSum >= k) {
                len = min(len, i + 1);
            }
            
            while (!Q.empty() and preSum - Q.front().first >= k) {
                len = min(len, i - Q.front().second);
                Q.pop_front();
            }
            
            while (!Q.empty() and preSum <= Q.back().first) {
                Q.pop_back();
            }
            
            Q.push_back({preSum, i});
        }
        
        return len == INT_MAX ? -1 : len;
    }
};

/*

5 -1 -1 -1 3

5 4 3 2 5



*/
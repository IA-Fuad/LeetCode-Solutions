class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> Q;
        int n = nums.size();
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            while (!Q.empty() and Q.back().first < nums[i]) {
                Q.pop_back();
            }
            Q.push_back({nums[i], i});
            int leftBound = i - k + 1;
            
            if (Q.front().second < leftBound) Q.pop_front();
            
            if (leftBound >= 0) ans.push_back(Q.front().first);
        }
        
        return ans;
    }
};

/*

7 5 1 4 3 9

5 4

4 3

9

*/
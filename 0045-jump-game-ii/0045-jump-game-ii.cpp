class Solution {
public:
    int jump(vector<int>& nums) {
        queue<pair<int, int>> Q;
        Q.push({0, 0});
        
        for (int i = 1; i < nums.size(); i++) {
            while (!Q.empty() and Q.front().first + nums[Q.front().first] < i) {
                Q.pop();
            }
            Q.push({i, Q.front().second + 1});
        }
        
        while (Q.size() > 1) Q.pop();
        
        return Q.front().second;
    }
};
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto& x, auto& y) {
            return x[1] < y[1];
        });
        
        int pairCount = 0, currEnd = INT_MIN;
        for (auto& pair : pairs) {
            if (pair[0] > currEnd) {
                pairCount++;
                currEnd = pair[1];
            }
        }
        
        return pairCount;
    }
};
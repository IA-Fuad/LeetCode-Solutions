class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> chainLengths(n, 1);
        int longestChain = 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (pairs[j][1] < pairs[i][0] && chainLengths[j]+1 > chainLengths[i]) {
                    chainLengths[i] = chainLengths[j] + 1;
                }
            }
            longestChain = max(longestChain, chainLengths[i]);
        }
        
        return longestChain;
    }
};
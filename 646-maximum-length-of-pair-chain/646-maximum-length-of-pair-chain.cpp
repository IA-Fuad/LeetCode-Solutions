class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), cmp);
//         vector<int> chainLengths(n, 1);
//         int longestChain = 1;
        
//         for (int i = 1; i < n; i++) {
//             for (int j = i-1; j >= 0; j--) {
//                 if (pairs[j][1] < pairs[i][0] && chainLengths[j]+1 > chainLengths[i]) {
//                     chainLengths[i] = chainLengths[j] + 1;
//                 }
//             }
//             longestChain = max(longestChain, chainLengths[i]);
//         }
        
//         return longestChain;
        int longestChain = 1, lastRight = pairs[0][1];
        for (int i = 1; i < n; i++) {
            if (pairs[i][0] > lastRight) {
                lastRight = pairs[i][1];
                longestChain++;
            }
        }
        return longestChain;
    }
    
    bool static cmp(vector<int>& x, vector<int>& y) {
        return x[1] < y[1];
    }
};
class Solution {
    vector<vector<vector<int>>> dp;
    
    int getMaxLen(vector<pair<int, int>>& binaryCount, int m, int n, int i, int z, int o) {
        if (i == binaryCount.size() or z > m or o > n) {
            return 0;
        }
        if (dp[i][z][o] != -1) {
            return dp[i][z][o];
        }
        
        auto[zeros, ones] = binaryCount[i];
        
        int take = 0;
        if (zeros+z <= m and ones+o <= n) {
            take = getMaxLen(binaryCount, m, n, i+1, z+binaryCount[i].first, o+binaryCount[i].second) + 1;
        }
        int doNotTake = getMaxLen(binaryCount, m, n, i+1, z, o);
        
        return dp[i][z][o] = max(take, doNotTake);
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        
        vector<pair<int, int>> binaryCount;
        
        for (auto& str : strs) {
            int ones = 0, zeros = 0;
            for (char b : str) {
                if (b == '1') ones++;
                else zeros++;
            }
            binaryCount.push_back({zeros, ones});
        }
        
        return getMaxLen(binaryCount, m, n, 0, 0, 0);
    }
};
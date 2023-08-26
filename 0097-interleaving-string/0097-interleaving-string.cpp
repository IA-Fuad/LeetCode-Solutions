class Solution {
//     vector<vector<vector<int>>> dp;
    
//     bool rec(const string& s1, const string& s2, const string& s3, int i, int j, int k) {
//         if (k == s3.size()) return true;
//         if (dp[k][i][j] != -1) return dp[k][i][j];
        
//         bool match = false;
//         if (i < s1.size() and s1[i] == s3[k]) match = rec(s1, s2, s3, i + 1, j, k + 1);
//         if (j < s2.size() and s2[j] == s3[k]) match |= rec(s1, s2, s3, i, j + 1, k + 1);
        
//         return dp[k][i][j] = match;
//     }
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), nm = s3.size();
        if (n + m != nm) return false;
        
//         dp.resize(nm, vector<vector<int>>(n+1, vector<int>(m+1, -1)));
//         return rec(s1, s2, s3, 0, 0, 0);
        
        vector<bool> dp(m+1);
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 and j == 0) {
                    dp[j] = true;
                    continue;
                }
                int k = i + j - 1;
                if (i == 0) {
                    dp[j] = dp[j-1] & (s2[j-1] == s3[k]);
                }
                else if (j == 0) {
                    dp[j] = dp[j] & (s1[i-1] == s3[k]);
                }
                else {
                    dp[j] = (dp[j] && s1[i-1] == s3[k]) || (dp[j-1] && s2[j-1] == s3[k]);
                }
            }
        }
        
        return dp[m];
    }
};
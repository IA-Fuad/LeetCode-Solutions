class Solution {
    vector<vector<int>> dp;
    int rec(const string& s, int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i] == s[j]) {
            return dp[i][j] = rec(s, i+1, j-1) + 2;
        }
        return dp[i][j] = max(rec(s, i+1, j), rec(s, i, j-1));
    }
    
public:
    int longestPalindromeSubseq(string s) {
        dp.resize(s.size(), vector<int>(s.size(), -1));
        return rec(s, 0, s.size()-1);
    }
};
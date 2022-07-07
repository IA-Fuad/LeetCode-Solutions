class Solution {
    int dp[205][105][105];
    int n, m, p;
    
    bool rec(const string& s1, const string& s2, const string& s3, int i, int j, int k) {
        if (p == k) return true;
        if (dp[k][i][j] != -1) return dp[k][i][j];
        
        bool a = false, b = false;
        
        if (i < n and s1[i] == s3[k]) {
            a = rec(s1, s2, s3, i+1, j, k+1);
        }
        if (j < m and s2[j] == s3[k]) {
            b = rec(s1, s2, s3, i, j+1, k+1);
        }
        
        return dp[k][i][j] = (a | b);
    } 
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size(), m = s2.size(), p = s3.size();
        
        if (n + m != p) return false;
        
        memset(dp, -1, sizeof dp);
        return rec(s1, s2, s3, 0, 0, 0);
    }
};
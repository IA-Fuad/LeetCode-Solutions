class Solution {
    vector<vector<int>> dp;
    
    int rec(const string& s1, const string& s2, int i, int j) {
        if (i == s1.size() || j == s2.size()) {
            int sum = 0;
            for (int k = i; k < s1.size(); k++) sum += (int)s1[k];
            for (int k = j; k < s2.size(); k++) sum += (int)s2[k];
            return sum;
        }
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s1[i] == s2[j]) {
            dp[i][j] = rec(s1, s2, i+1, j+1);
        }
        else {
            dp[i][j] = min(rec(s1, s2, i+1, j) + (int)s1[i], rec(s1, s2, i, j+1) + (int)s2[j]);
        }
        return dp[i][j];
    }
    
public:
    int minimumDeleteSum(string s1, string s2) {
        dp.resize(s1.size(), vector<int>(s2.size(), -1));

        return rec(s1, s2, 0, 0);
    }
};
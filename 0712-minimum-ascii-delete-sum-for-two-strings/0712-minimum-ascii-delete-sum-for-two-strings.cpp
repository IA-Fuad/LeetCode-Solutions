class Solution {
    int getASCIISum(const string& s, int i) {
        int sum = 0;
        for (int k = i; k < s.size(); k++) {
            sum += s[k];
        }
        return sum;
    }
    
    vector<vector<int>> dp;
    
    int rec(const string& s1, const string& s2, int i, int j) {
        if (i >= s1.size() and j >= s2.size()) return 0;
        if (i >= s1.size()) return getASCIISum(s2, j);
        if (j >= s2.size()) return getASCIISum(s1, i);
        
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j]) return rec(s1, s2, i + 1, j + 1);
        
        int a = rec(s1, s2, i + 1, j) + s1[i];
        int b = rec(s1, s2, i, j + 1) + s2[j];
        
        return dp[i][j] = min(a, b);
    }
    
public:
    int minimumDeleteSum(string s1, string s2) {
        dp.resize(s1.size(), vector<int>(s2.size(), -1));
        return rec(s1, s2, 0, 0);
    }
};
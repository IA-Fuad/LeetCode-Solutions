class Solution {
    vector<vector<int>> dp;
    
    bool allSame(const string& s, int l, int r) {
        for (int k = l; k <= r; k++) {
            if (s[k] != s[l]) return false;
        }
        return true;
    }
    int rec(const string& s, int l, int r) {
        if (allSame(s, l, r)) {
            return 0;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        
        int minTurn = s.size();
        
        for (int k = l; k < r; k++) {
            int a = rec(s, l, k) + (s[k] == s[r] ? 0 : 1);
            int b = rec(s, k + 1, r);
            //cout << l << ' ' <<  r << ' ' << a << ' ' << b << endl;
            minTurn = min(minTurn, a + b);    
        }
        
        return dp[l][r] = minTurn;
    }
    
public:
    int strangePrinter(string s) {
        dp.resize(s.size(), vector<int>(s.size(), -1));
        return rec(s, 0, s.size() - 1) + 1;
    }
};

/*

aaabacacaabcccaaa

aaaaaaaaaaaaaaaaa
aaabbbbbbbbaaaaaa
aaabaaaaaabaaaaaa
aaabacccaabaaaaaa
aaabacacaabaaaaaa

aaaaaaaaaaaaa
aaabbbbbbbaaa
aaabbcccbbaaa



*/
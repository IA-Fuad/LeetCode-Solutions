class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string word = word1 + word2;
        int N = word.size();
        int n = word1.size(), m = word2.size(), maxLen = 0;
        
        vector<vector<int>> dp(N, vector<int>(N));
        
        for (int j = 0; j < N; j++) {
            dp[j][j] = 1;
            
            for (int i = j-1; i >= 0; i--) {
                if (word[i] == word[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                    if (i < n and j >= n) maxLen = max(maxLen, dp[i][j]);
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
                //cout << i << ' ' << j << ' ' << word[i] << ' ' << word[j] << ' ' << dp[i][j] << endl;
            }
        }
        //cout << word << ' ' << dp[0][N-1] << endl;
        
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (word1[i] == word2[j]) {
//                     maxLen = max(maxLen, dp[i][j+n]);
//                 }
//             }
//         }
        
        return maxLen;
    }
};


/*

cacb|cbba



*/
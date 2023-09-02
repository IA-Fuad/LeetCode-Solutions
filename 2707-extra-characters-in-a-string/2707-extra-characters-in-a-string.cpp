class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> words;
        for (auto& word : dictionary) {
            words.insert(word);
        }
        
        int n = s.size();
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;
        
        for (int j = n-1; j >= 0; j--) {
            string currWord;
            for (int i = j; i < n; i++) {
                currWord.push_back(s[i]);
                if (words.find(currWord) != words.end()) {
                    dp[j] = min(dp[j], dp[i+1]);
                }
                else {
                    dp[j] = min(dp[j], (i - j + 1) + dp[i+1]);
                }
            }
        }
        
        return dp[0];
    }
};
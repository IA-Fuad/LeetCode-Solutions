class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<bool>> isWord(n+1, vector<bool>(n+1, false));
        unordered_map<string, bool> words;
        for (string& w : wordDict) {
            words[w] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            bool validWord = words.find(s.substr(0, i)) != words.end();
            for (int k = 1; k < i && !validWord; k++) {
                validWord = isWord[1][k] && (words.find(s.substr(k, i-k)) != words.end());
                //cout << s.substr(k, i-k) << ' ';
            }
            isWord[1][i] = validWord;
        }
        
        return isWord[1][n];
    }
};
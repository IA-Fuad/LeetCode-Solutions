class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> isWord(n+1);
        unordered_map<string, bool> words;
        for (string& w : wordDict) {
            words[w] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            bool validWord = words.find(s.substr(0, i)) != words.end();
            for (int k = 1; k < i && !validWord; k++) {
                validWord = isWord[k] && (words.find(s.substr(k, i-k)) != words.end());
                //cout << s.substr(k, i-k) << ' ';
            }
            isWord[i] = validWord;
        }
        
        return isWord[n];
    }
};
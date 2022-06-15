class Solution {
    bool isPred(const string& pred, const string& word) {
        if (pred.size() + 1 != word.size()) return false;
        
        int i, j;
        for (i = 0, j = 0; i < pred.size() and j < word.size(); j++) {
            if (pred[i] == word[j]) i++;
        } 
        
        return (i == pred.size() and j >= word.size()-1);
    }
    
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& x, const string& y) {
            return x.size() < y.size();
        });
        
        int n = words.size(), longestChain = 1;
        vector<int> lis(n, 1);
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
               // cout << words[j] << ' ' << words[i] << ' ' << isPred(words[j], words[i]) << endl;
                if (isPred(words[j], words[i]) and lis[j] + 1 > lis[i]) {
                    lis[i] = lis[j] + 1;
                    longestChain = max(longestChain, lis[i]);
                }
            }
        }
        
        return longestChain;
    }
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> markWords;
        for (string& w : wordList) {
            markWords[w] = true;
        }
        
        queue<pair<string, int>> Q;
        Q.push({beginWord, 1});
        markWords[beginWord] = false;
        
        while (!Q.empty()) {
            string currentWord = Q.front().first;
            int seqLen = Q.front().second;
            Q.pop();
            
            if (currentWord == endWord) {
                return seqLen;
            }
            
            for (int i = 0; i < currentWord.size(); i++) {
                string temp = currentWord;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    
                    auto it = markWords.find(temp);
                    if (it != markWords.end() && it->second) {
                        Q.push({temp, seqLen+1});
                        it->second = false;
                    }
                }
            }
        }
        
        return 0;
    }
};
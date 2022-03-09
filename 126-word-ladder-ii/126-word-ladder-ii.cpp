class Solution {
    typedef unordered_map<string, vector<string>> WordChilds;
    void rec(WordChilds& words, vector<vector<string>>& ans, vector<string>& currentSeq, string word, const string& endWord) {
        if (word == endWord) {
            ans.push_back(currentSeq);
            return;
        }
        
        for (auto child : words[word]) {
            currentSeq.push_back(child);
            rec(words, ans, currentSeq, child, endWord);
            currentSeq.pop_back();
        }
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return {{beginWord}};
        
        unordered_map<string, int> seenAtLevel;
        for (string& word : wordList) {
            seenAtLevel[word] = -1;
        }
        
        WordChilds childs;
        
        int level = 0;
        seenAtLevel[beginWord] = level;
        queue<string> Q;
        Q.push(beginWord);
        bool foundEndWord = false;
        
        while (!Q.empty() and !foundEndWord) {
            int currentQSize = Q.size();

            while (--currentQSize >= 0) {
                string currentWord = Q.front();
                Q.pop();
                
                string nextWord = currentWord;
                for (int i = 0; i < currentWord.size(); i++) {
                    char cc = nextWord[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == cc) continue;
                        nextWord[i] = c;
                        auto it = seenAtLevel.find(nextWord);
                        if (it != seenAtLevel.end() and (it->second == level or it->second == -1)) {
                            if (nextWord == endWord) {
                                foundEndWord = true;
                            }
                            if (it->second != level) {
                                Q.push(nextWord);
                            }
                            it->second = level;
                            childs[currentWord].push_back(nextWord);
                        }
                    }
                    nextWord[i] = cc;
                }
            }
            
            level++;
        }
        
        vector<vector<string>> ans;
        vector<string> currentSeq = {beginWord};
        
        if (!foundEndWord) return ans;

        rec(childs, ans, currentSeq, beginWord, endWord);
        
        return ans;
    }
};
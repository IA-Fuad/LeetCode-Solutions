class Solution {
    unordered_map<string, vector<string>> adjWords;
    unordered_map<string, vector<string>> parents;
    unordered_set<string> words;
    vector<vector<string>> ladders;
    
    void buildAdjWords() {
        for (string word : words) {
            string w = word;
            
            for (char c = 'a'; c <= 'z'; c++) {
                for (int i = 0; i < word.size(); i++) {
                    if (c == word[i]) continue;
                    char orig = word[i];
                    word[i] = c;
                    
                    if (words.find(word) != words.end()) {
                        adjWords[w].push_back(word);
                    }
                    word[i] = orig;
                }
            }
        }
    }
    
    void bfs(string& beginWord, string& endWord) {
        queue<string> Q;
        Q.push(beginWord);
        
        int level = 0;
        unordered_map<string, int> seenAtLevel;
        seenAtLevel[beginWord] = level;
        bool endFound = false;
        
        while (!Q.empty() and !endFound) {
            level++;
            int currentSize = Q.size();
            
            for (int k = 0; k < currentSize; k++) {
                string word = Q.front();
                Q.pop();

                auto adj = adjWords.find(word);
                if (adj == adjWords.end()) continue;

                for (string w : adj->second) {
                    auto seen = seenAtLevel.find(w);
                    
                    if (seen == seenAtLevel.end()) {
                        Q.push(w);
                        seenAtLevel[w] = level;
                    }
                    if (w != word and (seen == seenAtLevel.end() or seen->second == level)) {
                        parents[w].push_back(word);
                    }
                    
                    if (w == endWord) endFound = true;
                }   
            }
        }
        
        return;
    }
    
    void rec(vector<string>& ladder, const string& currentWord, const string& beginWord, int level) {
        if (currentWord == beginWord) {
            ladders.push_back(ladder);
            return;
        }
        
        for (string w : parents[currentWord]) {
            ladder.push_back(w);
            rec(ladder, w, beginWord, level+1);
            ladder.pop_back();
        }
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for (const string& word : wordList) {
            words.insert(word);
        }
        words.insert(beginWord);
        
        if (words.find(endWord) == words.end()) return {};
        
        buildAdjWords();
        bfs(beginWord, endWord);

        vector<string> ladder = {endWord};
        //cout << parents[endWord].size() << ' ';
        rec(ladder, endWord, beginWord, 0);
        
        for (auto& ladder : ladders) {
            reverse(ladder.begin(), ladder.end());
        }
        
        return ladders;
    }
};
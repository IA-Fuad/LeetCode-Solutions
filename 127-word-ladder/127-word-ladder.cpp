class Solution {
public:
    enum WordStatus {
        NotVisited = 0,
        VisitedFromBegin = 1,
        VisitedFromEnd = 2
    };
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, WordStatus> markWords;
        for (string& w : wordList) {
            markWords[w] = NotVisited;
        }
        
        queue<pair<string, int>> Qb, Qe;
        Qb.push({beginWord, 1});
        Qe.push({endWord, 1});
        markWords[beginWord] = VisitedFromBegin;
        //markWords[endWord] = VisitedFromEnd;
        
        while (!Qb.empty()) {
            string currentWordFromBegin = Qb.front().first;
            string currentWordFromEnd = Qe.front().first;
            int seqLenFromBegin = Qb.front().second;
            int seqLenFromEnd = Qe.front().second;
            Qb.pop();
           // Qe.pop();
            if (currentWordFromBegin == endWord) return seqLenFromBegin;
            
            for (int i = 0; i < currentWordFromBegin.size(); i++) {
                string temp = currentWordFromBegin;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    
                    auto it = markWords.find(temp);
                    if (it != markWords.end() && it->second != VisitedFromBegin) {
                        Qb.push({temp, seqLenFromBegin+1});
                        it->second = VisitedFromBegin;
                    }
                }
            }
            
         
        }
        
        return 0;
    }
};
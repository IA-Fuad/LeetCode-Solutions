class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> startIndices;
        unordered_map<string, int> wordCount;
        int num = 0;
        
        for (string& word : words) {
            wordCount[word]++;
        }
        
        int wordSize = words[0].size(), totalWords = words.size(), totalWordSize = wordSize * totalWords;
        vector<int> ans;
        
        for (int i = 0; i < wordSize; i++) {
            int cnt = 0;
            unordered_map<string, int> seen;
            
            for (int left = i, right = i; right < s.size(); right += wordSize) {
                string w = s.substr(right, wordSize);
                auto wc = wordCount.find(w);
                
                while ((wc == wordCount.end() or seen[w] == wc->second) and left <= right) {
                    string wr = s.substr(left, wordSize);
                    seen[wr]--;
                    left += wordSize;
                }
                
                seen[w]++;

                if ((right + wordSize) - left == totalWordSize) ans.push_back(left);
            }
        }
        
        return ans;
    }
};
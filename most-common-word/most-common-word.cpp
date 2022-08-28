class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> wordCount;
        string word, mostFreqWord;
        int maxFreq = 0, n = paragraph.size();
        
        for (string& bannedWord : banned) {
            wordCount[bannedWord] = -1;
        }
        
        for (int i = 0; i <= n; i++) {
            char c = i < n ? tolower(paragraph[i]) : 'x';
            
            if (i < n and c >= 'a' and c <= 'z') {
                word.push_back(c);
            }
            else if (word.size() > 0) {
                auto it = wordCount.find(word);
                if (it == wordCount.end() or it->second != -1) {
                    wordCount[word]++;
                    if (wordCount[word] > maxFreq) {
                        maxFreq = wordCount[word];
                        mostFreqWord = word;
                    }
                }
                word.clear();
            }
        }
        
        return mostFreqWord;
    }
};
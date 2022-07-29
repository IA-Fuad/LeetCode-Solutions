class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> matched;
        int patternSize = pattern.size();
        for (const string& word : words) {
            if (word.size() != patternSize) {
                continue;
            }
            
            vector<int> charMap(26, -1);
            vector<bool> alreadyMapped(26, false);
            bool match = true;
            
            for (int i = 0; i < patternSize and match; i++) {
                int charId = pattern[i] - 'a';
                if (charMap[charId] == -1) {
                    if (alreadyMapped[word[i]-'a']) {
                        match = false;
                    }
                    charMap[charId] = word[i];
                    alreadyMapped[word[i]-'a'] = true;
                }
                else if (charMap[charId] != word[i]) {
                    match = false;
                }
            }
            
            if (match) {
                matched.push_back(word);
            }
        }
        
        return matched;
    }
};
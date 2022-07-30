class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> charCount(26, 0);
        
        for (const string& word : words2) {
            vector<int> currentWordCharCount(26, 0);
            
            for (char c : word) {
                currentWordCharCount[c-'a']++;
                if (currentWordCharCount[c-'a'] > charCount[c-'a']) {
                    charCount[c-'a'] = currentWordCharCount[c-'a'];
                }
            }
        }
        
        vector<string> universalStrings;
        
        for (const string& word : words1) {
            vector<int> currentWordCharCount(26, 0);
            
            for (char c : word) {
                currentWordCharCount[c-'a']++;
            }
            
            bool isUniversal = true;
            
            for (int i = 0; i < 26; i++) {
                if (charCount[i] > currentWordCharCount[i]) {
                    isUniversal = false;
                    break;
                }
            }
            
            if (isUniversal) {
                universalStrings.push_back(word);
            }
        }
        
        return universalStrings;
    }
};
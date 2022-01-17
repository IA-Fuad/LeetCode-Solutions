class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, int> markWord;
        unordered_map<char, int> markChar;
        
        int pind = 0, sind = 0, ss = s.size(), ps = pattern.size(), i, j;
        for (i = 0, j = 0; i < ps; i++, j++) {
            auto itChar = markChar.find(pattern[i]);
            if (itChar == markChar.end()) {
                markChar[pattern[i]] = pind++;
            }
            string word = "";
            for (; j < ss && s[j] != ' '; j++) {
                word += s[j];
            }
            auto itWord = markWord.find(word);
            if (itWord == markWord.end()) {
                markWord[word] = sind++;
            }
            if (markChar[pattern[i]] != markWord[word]) return false; 
        }
        return i == ps && j-1 == ss;
    }
};
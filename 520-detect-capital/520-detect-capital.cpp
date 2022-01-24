class Solution {
    bool isCapital(char c) {
        return c >= 'A' && c <= 'Z';
    }
    
public:
    bool detectCapitalUse(string word) {
        if (word.size() < 2) return true;
        int capitalCount = 0, smallCount = 0;
        for (char c : word) {
            if (isCapital(c)) capitalCount++;
            else smallCount++;
        }
        if (capitalCount == word.size() || smallCount == word.size()) return true;
        return capitalCount == 1 && isCapital(word[0]);
    }
};
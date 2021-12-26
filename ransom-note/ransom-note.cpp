class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int charCount[26] = {0};
        for (char c : magazine) charCount[c-'a']++;
        for (char c : ransomNote) {
            if (charCount[c-'a'] < 1) return false;
            charCount[c-'a']--;
        }
        return true;
    }
};
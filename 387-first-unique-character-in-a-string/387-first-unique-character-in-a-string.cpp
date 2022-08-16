class Solution {
public:
    int firstUniqChar(string s) {
        int charCount[26] = {0};
        for (char c : s) charCount[c-'a']++;
        for (int i = 0; s[i]; i++) if (charCount[s[i]-'a'] == 1) return i;
        return -1;
    }
};
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> charCount(26, 0);
        for (char c : s) {
            charCount[c-'a']++;
        }
        for (char c : t) {
            charCount[c-'a']--;
        }
        char diff;
        for (char c : t) {
            if (charCount[c-'a'] == -1) {
                diff = c;
                break;
            }
        }
        return diff;
    }
};
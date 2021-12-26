class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> charCount;
        for (char c : s) charCount[c]++;
        int n = s.size();
        for (char c : t) {
            if (charCount[c] < 1) return false;
            charCount[c]--, n--;
        }
        if (n != 0) return false;
        return true;
    }
};
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> charCount(26, 0);
        for (char c : p) {
            charCount[c-'a']++;
        }
        
        vector<int> startInds;
        
        for (int i = 0, j = 0; j < s.size(); j++) {
            charCount[s[j]-'a']--;
            if (j - i == p.size()-1) {
                bool isAnagram = true;
                for (int i = 0; i < 26; i++) {
                    if (charCount[i] != 0) {
                        isAnagram = false;
                        break;
                    }
                }
                if (isAnagram) startInds.push_back(i);
                charCount[s[i]-'a']++;
                i++;
            }
        }
        
        return startInds;
    }
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        
        if (n > m) {
            return false;
        }
        
        vector<int> charCount(26, 0), rangeCharCount(26, 0);
        
        for (char c : s1) {
            charCount[c-'a']++;
        }

        bool doesContain = false;
        
        for (int i = 0; i < m && !doesContain; i++) {
            int c = s2[i] - 'a';
            charCount[c]--;
            if (i >= n) {
                int c2 = s2[i-n] - 'a';
                charCount[c2]++;
            }
            
            doesContain = true;
            for (int k = 0; k < 26; k++) {
                if (charCount[k] != 0) {
                    doesContain = false;
                    break;
                }
            }
        }
        
        return doesContain;
    }
};
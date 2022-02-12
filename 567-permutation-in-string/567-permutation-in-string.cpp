class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        
        if (n > m) {
            return false;
        }
        
        vector<int> charCount(26, 0);
        int distinctChars = 0;
        
        for (char c : s1) {
            charCount[c-'a']++;
            distinctChars += charCount[c-'a'] == 1 ? 1 : 0;
        }

        for (int i = 0, k = 0; i < m; i++) {
            int c = s2[i] - 'a';
            charCount[c]--;
            
            if (charCount[c] == 0) distinctChars--;

            if (i >= n) {
                int c2 = s2[i-n] - 'a';
                charCount[c2]++;
                
                if (charCount[c2] == 1) distinctChars++;
            }
            
            if (distinctChars == 0) return true;
        }
        
        return false;
    }
};
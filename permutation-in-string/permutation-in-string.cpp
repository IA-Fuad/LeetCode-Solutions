class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size(), m = s1.size();
        vector<vector<int>> charCount(n+1, vector<int>(26, 0));
        charCount[1][s2[0]-'a'] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int k = 0; k < 26; k++) {
                charCount[i][k] = charCount[i-1][k];
            }
            charCount[i][s2[i-1]-'a']++;
        }
        
        int mainCharCount[26] = {0};
        for (char c : s1) mainCharCount[c-'a']++;
        
        for (int i = m; i <= n; i++) {
            bool flag = true;
            for (int k = 0; k < 26 && flag; k++) {
                if (charCount[i][k]-charCount[i-m][k] != mainCharCount[k]) flag = false;
            }
            if (flag) return flag;
        }
        return false;
    }
};
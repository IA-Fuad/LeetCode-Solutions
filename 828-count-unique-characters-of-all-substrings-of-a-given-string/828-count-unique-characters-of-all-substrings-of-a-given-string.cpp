class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size(), ans = 0;
        vector<int> seenLen(26, 0);
        vector<int> lastCharIndex(26, -1);
        
        for (int i = 0; i < n; i++) {
            seenLen[s[i]-'A'] = i - lastCharIndex[s[i]-'A'];
            lastCharIndex[s[i]-'A'] = i;
            
            for (char c = 0; c < 26; c++) {
                ans += seenLen[c];
            }
        }
        
        return ans;
    }
};

/*

1 + 3 + 3 + 6 + 10 + 15 + 21 + 21

1 2 2 3 4 5 6 6


1 + 3 + 1 + 3

*/
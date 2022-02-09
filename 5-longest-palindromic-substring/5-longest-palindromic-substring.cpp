class Solution {
    pair<int, int> getPalindromeLenFromTheCenter(const string& s, int l, int r) {
        if (s[l] != s[r]) {
            return {1, l};
        }
        while (l >= 0 && r < s.size()) {
            if (s[l] != s[r]) {
                break;
            }
            l--;
            r++;
        }
        return {r - l - 1, l + 1};
    }
    
public:
    string longestPalindrome(string s) {
        int mxLen = 1, startInd = 0;
        
        for (int i = 0; i < s.size(); i++) {
            auto palindromeLenAndStartInd1 = getPalindromeLenFromTheCenter(s, i, i);
            auto palindromeLenAndStartInd2 = getPalindromeLenFromTheCenter(s, i, i+1);
            
            if (mxLen < palindromeLenAndStartInd1.first) {
                mxLen = palindromeLenAndStartInd1.first;
                startInd = palindromeLenAndStartInd1.second;
            }
            if (mxLen < palindromeLenAndStartInd2.first) {
                mxLen = palindromeLenAndStartInd2.first;
                startInd = palindromeLenAndStartInd2.second;
            }
        }
        
        return s.substr(startInd, mxLen);
    }
};
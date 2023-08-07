class Solution {
public:
    int countBinarySubstrings(string s) {
        bool countingOne = s[0] == '1';
        int curr = 1, prev = 0, bs = 0;
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i-1]) {
                bs += min(curr, prev);
                prev = curr;
                curr = 0;
            }
            curr++;
        }
        
        return bs + min(curr, prev);
    }
};
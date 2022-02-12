class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128, -1);
        int mxLen = 0;
        
        for (int l = -1, r = 0; r < s.size(); r++) {
            l = max(l, lastIndex[s[r]]);
            mxLen = max(mxLen, r - l);
            lastIndex[s[r]] = r;
        }
        
        return mxLen;
    }
};
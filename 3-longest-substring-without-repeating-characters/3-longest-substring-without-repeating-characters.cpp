class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charCount;
        int mxLen = 0;
        
        for (int l = 0, r = 0; r < s.size(); r++) {
            charCount[s[r]]++;
            while (charCount[s[r]] > 1) {
                charCount[s[l]]--;
                l++;
            }
            mxLen = max(mxLen, r - l + 1);
        }
        
        return mxLen;
    }
};
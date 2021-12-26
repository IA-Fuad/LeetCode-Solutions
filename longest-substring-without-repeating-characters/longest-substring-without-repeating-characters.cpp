class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mxLen = 0, pri = 0;
        unordered_map<char, int> latestIndex;
        
        for (int i = 1; i <= s.size(); i++) {
            int k = latestIndex[s[i-1]];
            mxLen = max(mxLen,  i - max(k, pri));
            pri = max(k, pri), latestIndex[s[i-1]] = i;
            //cout << mxLen << ' ';
        }
        
        return mxLen;
    }
};
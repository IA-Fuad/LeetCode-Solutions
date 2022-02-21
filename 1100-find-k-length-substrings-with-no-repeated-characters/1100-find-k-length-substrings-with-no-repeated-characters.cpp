class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        unordered_map<char, int> charIndx;
        int ans = 0;
        
        for (int i = 0, j = 0; i < s.size(); i++) {
            auto it = charIndx.find(s[i]);
            if (it != charIndx.end()) {
                j = it->second + 1 < j ? j : it->second + 1;
            }
            if (i - j >= k - 1) {
                ans++;
            }
            charIndx[s[i]] = i;
            
        }
        
        return ans;
    }
};
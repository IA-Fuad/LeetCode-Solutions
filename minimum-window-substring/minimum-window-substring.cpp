class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tCharCount;
        int nonZeroCount = 0, left = -1, right = -1;
        
        for (char c : t) {
            auto it = tCharCount.find(c);
            if (it == tCharCount.end()) {
                tCharCount[c] = 1;
                nonZeroCount++;
            }
            else {
                it->second++;
            }
        }
        
        for (int l = 0, r = 0; r < s.size(); r++) {
            char sr = s[r], sl = s[l];
            
            auto it = tCharCount.find(sr);
            if (it != tCharCount.end()) {
                it->second--;
                
                if (it->second == 0) {
                    nonZeroCount--;
                }
            }

            while (l < r) {
                it = tCharCount.find(s[l]);
                if (it != tCharCount.end() and it->second >= 0) break;
                if (it != tCharCount.end()) it->second++;
                l++;
            }
            
            if (nonZeroCount == 0 and (right == -1 or (r - l < right - left))) {
                left = l, right = r;
            }
        }
        
        if (right == -1) return "";
        return s.substr(left, right - left + 1);
    }
};
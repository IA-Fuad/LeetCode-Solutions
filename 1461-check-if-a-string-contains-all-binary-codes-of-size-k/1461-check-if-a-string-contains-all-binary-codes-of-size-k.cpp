class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;
        
        unordered_set<int> mark;
        int x = 0;
        
        for (int i = s.size()-1, j = 0; j < k; i--, j++) {
            if (s[i] == '1') {
                x |= (1 << j);
            }
        }
        mark.insert(x);
        
        for (int i = s.size()-(k+1); i >= 0; i--) {
            x >>= 1;
            if (s[i] == '1') x |= (1 << (k-1));
            mark.insert(x);
        }
        
        for (int i = 0; i < (1 << k); i++) {
            if (mark.find(i) == mark.end()) return false;
        }
        
        return true;
    }
};
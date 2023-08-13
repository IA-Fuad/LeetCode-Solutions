class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.size() - 1;
        
        while (l < r and s[l] == s[r]) {
            int i = l - 1, j = r + 1;
            while (s[++i] == s[l]);
            while (i <= j and s[--j] == s[r]);
            l = i, r = j;
        }
        
        return r - l + 1;
    }
};
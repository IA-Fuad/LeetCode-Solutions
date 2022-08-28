class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size(), m = t.size();
        
        if (n == m) {
            int misplacedCount = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] != t[i]) {
                    misplacedCount++;
                    if (misplacedCount > 1) return false;
                }
            }
            return misplacedCount == 1;
        }
        if (abs(n - m) > 1) return false;
        
        if (n < m) {
            swap(s, t);
            swap(n, m);
        }
        
        for (int i = 0, j = 0; i < n; ) {
            if (j == m and i == n-1) return true;
            if (s[i] != t[j]) i++;
            else i++, j++;
            if (i - j > 1) return false;
        }
        
        return true;
    }
};
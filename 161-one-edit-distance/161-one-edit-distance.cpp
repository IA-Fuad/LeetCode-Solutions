class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size(), m = t.size();
        
        if (abs(n - m) > 1) return false;
        if (n < m) {
            swap(s, t);
            swap(n, m);
        }
        
        int misplacedCount = 0;
        
        for (int i = 0, j = 0; i < n and j < m; ) {
            if (s[i] != t[j]) {
                misplacedCount++;
                if (n > m) i++;
                else i++, j++;
            }
            else i++, j++;
        }
        
        return misplacedCount == 1 or (misplacedCount == 0 and n > m);
    }
};
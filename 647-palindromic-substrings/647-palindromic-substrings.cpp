class Solution {  
    int getPalindromeCountAroundCenter(const string& s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.size()) {
            if (s[l] != s[r]) {
                break;
            }
            l--;
            r++;
            count++;
        }
        return count;
    }
    
public:
    int countSubstrings(string s) {
        int n = s.size();
        int palindromeCount = 0;

        for (int i = 0; i < n; i++) {
            palindromeCount += getPalindromeCountAroundCenter(s, i, i);
            palindromeCount += getPalindromeCountAroundCenter(s, i, i+1);
        }
        
        return palindromeCount;
    }
};
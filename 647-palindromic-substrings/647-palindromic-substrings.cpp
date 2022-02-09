class Solution {   
    void rec(int l, int r) {
        for (int i = l; i <= r; i++) {}
    }
    
    
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<bool> isPalindrome(n, false);
        int palindromeCount = 0;
 
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                if (i == j) {
                    isPalindrome[i] = true;
                }
                else if (j == i+1) {
                    isPalindrome[i] = s[i] == s[j];
                }
                else {
                    isPalindrome[i] = isPalindrome[i+1] & s[i] == s[j];
                }
                if (isPalindrome[i]) {
                    palindromeCount++;
                }
            }
        }
        
        return palindromeCount;
    }
};
class Solution {   
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        int palindromeCount = 0;
 
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                if (i == j) {
                    isPalindrome[i][j] = true;
                }
                else if (j == i+1) {
                    isPalindrome[i][j] = s[i] == s[j];
                }
                else {
                    isPalindrome[i][j] = isPalindrome[i+1][j-1] & s[i] == s[j];
                }
                if (isPalindrome[i][j]) {
                    palindromeCount++;
                }
            }
        }
        
        return palindromeCount;
    }
};
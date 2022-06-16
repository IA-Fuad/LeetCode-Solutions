class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxLen = 1, l = 0;
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    
        for (int i = n-1; i >= 0; i--) {
            isPalindrome[i][i] = true;
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j]) {
                    if (i+1 == j) isPalindrome[i][j] = true;
                    else isPalindrome[i][j] = isPalindrome[i+1][j-1];
                    
                    if (isPalindrome[i][j] and j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        l = i;
                    }
                }
            }
        }
        
        return s.substr(l, maxLen);
    }
};
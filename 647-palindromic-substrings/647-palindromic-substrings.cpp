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
        //vector<bool> isPalindrome(n, false);
        int palindromeCount = 0;
 
        // for (int j = 0; j < n; j++) {
        //     for (int i = 0; i <= j; i++) {
        //         if (i == j) {
        //             isPalindrome[i] = true;
        //         }
        //         else if (j == i+1) {
        //             isPalindrome[i] = s[i] == s[j];
        //         }
        //         else {
        //             isPalindrome[i] = isPalindrome[i+1] & s[i] == s[j];
        //         }
        //         if (isPalindrome[i]) {
        //             palindromeCount++;
        //         }
        //     }
        // }
        for (int i = 0; i < n; i++) {
            palindromeCount += getPalindromeCountAroundCenter(s, i, i);
            palindromeCount += getPalindromeCountAroundCenter(s, i, i+1);
        }
        
        return palindromeCount;
    }
};
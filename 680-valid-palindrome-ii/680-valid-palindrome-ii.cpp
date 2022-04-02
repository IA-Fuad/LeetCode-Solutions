class Solution {
    bool check(const string& s, int i, int j, bool canDelete) {
        if (i >= j) return true;
        if (s[i] != s[j] and !canDelete) return false;
        if (s[i] != s[j]) {
            return check(s, i+1, j, false) | check(s, i, j-1, false);
        }
        return check(s, i+1, j-1, canDelete);
    }
    
public:
    bool validPalindrome(string s) {
        return check(s, 0, s.size()-1, true);
    }
};

/*

adbccbda

*/
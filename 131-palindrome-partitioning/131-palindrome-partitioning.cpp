class Solution {
    vector<vector<string>> ans;
    vector<string> palin;
    
    string isPalindrome(const string& s, int i, int k) {
        string t = "";
        for (int l = i, r = i+k-1; l < r; l++, r--) {
            if (s[l] != s[r]) return "";
        }
        for (int l = i; l < i+k; l++) t += s[l];
        return t;
    }
    
    void rec(const string& s, int i, int n) {
        if (i >= n) {
            ans.push_back(palin);
            return;
        }
        for (int k = 1; k+i <= n; k++) {
            string p = isPalindrome(s, i, k);
            if (p != "") {
                palin.push_back(p);
                rec(s, i+k, n);
                palin.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        rec(s, 0, s.size());
        return ans;
    }
};
class Solution {
    vector<vector<string>> ans;
    vector<string> palin;
    vector<vector<bool>> isPalin;
    
    string isPalindrome(const string& s, int i, int k) {
        if (k == 1) {
            isPalin[i][i] = true;
            return s.substr(i, k);
        }
        else if (s[i] == s[i+k-1] && (k == 2 || isPalin[i+1][i+k-2])) {
            isPalin[i][i+k-1] = true;
            return s.substr(i, k);
        }
        return "";
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
        isPalin.resize(s.size()+1, vector<bool>(s.size()+1, false));
        rec(s, 0, s.size());
        return ans;
    }
};
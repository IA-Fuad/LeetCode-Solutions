class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string x, rev = "";
        
        while (ss >> x) {
            reverse(x.begin(), x.end());
            rev += x;
            rev += ' ';
        }
        rev.pop_back();
        
        return rev;
    }
};